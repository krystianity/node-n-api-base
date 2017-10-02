"use strict";

const addon = require("./../addon.js");

const run = () => {

    console.log(addon.hello(), addon.hello("hi "));

    addon.helloCall(false, {}, (error, result) => {
        console.log(error, result);
    });
    
    addon.helloCall(true, {}, (error, result) => {
        console.log(error, result);
    });

    console.log("called");
};

module.exports = {run};