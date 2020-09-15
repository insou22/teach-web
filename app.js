'use strict';

const fs = require('fs');

const nunjucks = require('nunjucks');
const express = require('express');

const capacity = require('./tools/capacity');
const data = require('./data.json');

const app = express();
const port = 9987;

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

    for (const session of data.sessions) {
        if (session.year == new Date().getFullYear() % 100) {
            for (const clazz of session.classes) {
                const cap = await capacity.getCapacity(session.term, clazz.classNum);

                clazz['enrolment'] = cap;
            }
        }
    }

    return res.render('index.njk', templateData);
});

data.sessions.forEach((session) => {
    const sessionName = `${session.year}T${session.term}`;

    app.get(`/${sessionName}`, async (req, res) => {
        return res.render('session.njk', session);
    });

    session.classes.forEach((clazz) => {
        app.get(`/${sessionName}/${clazz.name}`, async (req, res) => {
            return res.render('class.njk', {
                class: clazz,
                session: sessionName,
                sessionCurrent: session.current
            });
        });

        if (session.current) {
            clazz.tutorials.forEach((tute) => {
                const endpoint = `/${sessionName}/${clazz.name}/feedback/${tute.week}`;

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

                    const name = `${sessionName}.${clazz.name}.${tute.week}-${date}`;

                    fs.writeFile(`./feedback/${name}.json`, JSON.stringify(req.body, null, 4), () => {
                        console.log(`Received new feedback at ${date}`);
                    });

                    return res.render('feedback_success.njk', {
                        data,
                        class: clazz,
                        tute,
                        session: sessionName
                    });
                });
            });
        }
    });
});

app.listen(port, () => console.log(`teach-web listening at http://localhost:${port}`));