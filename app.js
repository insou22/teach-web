'use strict';

const fs = require('fs');

const nunjucks = require('nunjucks');
const express = require('express');

const capacity = require('./tools/capacity');
const data = require('./data.json');

const app = express();
const port = 3000;

nunjucks.configure('views', {
    autoescape: true,
    express: app
});

app.use(express.static('public'));
app.use(express.urlencoded({
    extended: true
}));

app.get('/', async (req, res) => {
    const templateData = {
        data
    };

    for (const clazz of data.classes) {
        const cap = await capacity.getCapacity(clazz.classNum);
        
        clazz['enrolment'] = cap;
    }

    return res.render('index.njk', templateData);
});

data.classes.forEach((clazz) => {
    app.get(`/${clazz.name}`, async (req, res) => {
        return res.render('class.njk', clazz);
    });

    clazz.tutorials.forEach((tute) => {
        const endpoint = `/${clazz.name}/feedback/${tute.week}`;

        app.get(endpoint, async (req, res) => {
            return res.render('feedback.njk', {
                data,
                class: clazz,
                tute
            });
        });

        app.post(endpoint, async (req, res) => {
            req.body.share = req.body.share === 'on';

            const date = new Date().toISOString()
                .replace(/T/, '_')
                .replace(/\..+/, '');

            const name = `${clazz.name}.${tute.week}-${date}`;

            fs.writeFile(`./feedback/${name}.json`, JSON.stringify(req.body, null, 4), () => {
                console.log(`Received new feedback at ${date}`);
            });

            return res.render('feedback_success.njk', {
                data,
                class: clazz,
                tute
            });
        });
    })
});

app.listen(port, () => console.log(`teach-web listening at http://localhost:${port}`));