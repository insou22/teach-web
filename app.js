'use strict';

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

app.listen(port, () => console.log(`teach-web listening at http://localhost:${port}`));