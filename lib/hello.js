"use strict";

const addon = require("./../addon.js");

const run = () => {
    console.log("hello " + addon.hello());
};

module.exports = {run};