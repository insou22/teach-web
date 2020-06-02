'use strict';

const _ = require('lodash');
const axios = require('axios').default;
const parser = require('node-html-parser');

const facultyRegex = new RegExp(/\d+/);
const courseRegex = new RegExp(/^[A-Za-z]+\d+\s*$/);

const mergeObjects = (array) => 
    _.reduce(array, (object, current) => ({
        ...object, ...current
    }), {});

const getFacultyFromCourse = (course) => {
    return course.split(facultyRegex)[0]
};

/*
    faculty = "COMP"
    term = 2

    return = {
        "COMP1000": [
            "1850" {
                "current": "38",
                "max": "142"
            },
            "7731" {
                "current": "20",
                "max": "34"
            },
            ...
        ],
        ...
    }
*/
const checkAvailability = async (faculty, term) => {
    const termLetter = term != 0 ? 'T' : 'U';
    const termNumber = term != 0 ? term : 1; 
    const url = `http://classutil.unsw.edu.au/${faculty}_${termLetter}${termNumber}.html`;
            
    const response = await axios.get(url)
        .catch(err => {
            console.error(`Error requesting classUtil url=${url}`);
            console.error(`Error = ${err} , JSON = ${JSON.stringify(err)}`);
        });

    const entries = [];

    const dom = parser.parse(response.data);

    // big table is 2nd
    const bigTable = dom.querySelectorAll('table')[1];
    const rows = bigTable.querySelectorAll('tr');

    const bigParse = _(rows)
        .flatMap(row => row.querySelectorAll('td'))
        .map(display => display.text)
        .value()
        .slice(8);

    for (let index = 0; index < bigParse.length; ) {
        const course = bigParse[index++].trim();

        if (course === '^ top ^') break;

        const classes = [];

        // skip name of course
        index++;

        while (!courseRegex.test(bigParse[index]) && bigParse[index] != '^ top ^') {
            index++; // class type
            index++; // class time
            const classNum = parseInt(bigParse[index++].trim());
            index++; // enrolment type
            index++; // status
            const spots = bigParse[index++].trim();
            index++; // percent full
            index++; // times / locations

            const spotsParts = spots.split(/(\/)|(\s)/g);
            const current = parseInt(spotsParts[0]);
            const max = parseInt(spotsParts[3]);

            classes.push({
                [classNum]: {
                    current,
                    max
                }
            });
        }

        entries.push({
            [course]: mergeObjects(classes)
        });
    }

    return mergeObjects(entries);
}

/*
    requests = [
        {
            faculty: "COMP",
            term: 2
        },
        ...
    ]

    return = {
        "COMP": {
            "2": {
                "COMP1000": [
                    "1850": {
                        "current": "38",
                        "max": "142"
                    },
                    "7731": {
                        "current": "20",
                        "max": "34"
                    },
                    ...
                ],
                ...
            },
            ...
        },
        ...
    }
*/
const checkAvailabilities = async (requests) => {
    const toLoad = _(requests)
        .uniqWith(_.isEqual)
        .value();

    return mergeObjects(
        await Promise.all(
            _.map(toLoad, async (req) => ({
                [req.faculty]: {
                    [req.term]: await checkAvailability(req.faculty, req.term)
                }
            }))
        )
    );
};

exports.getFacultyFromCourse = getFacultyFromCourse;
exports.checkAvailability = checkAvailability;
exports.checkAvailabilities = checkAvailabilities;
