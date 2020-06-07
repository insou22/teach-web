#!/bin/sh

cd /etc/teach-web
git pull
npm install --production
pm2 restart 'teach-web'