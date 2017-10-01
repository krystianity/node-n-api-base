"use strict";

const addon = require("./../addon.js");

const run = () => {

    console.log(addon.hello());
    
    addon.callme((...args) => {
        console.log(...args);
    });

    console.log("called");
};

module.exports = {run};