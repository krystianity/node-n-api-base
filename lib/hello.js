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

const runBench = (times = 1e6) => {

    const startT = Date.now();
    recursivePlain(times, () => {
        console.log("rp took:", (Date.now() - startT), "ms");

        const startT1 = Date.now();
        recursiveHelloWorld(times, () => {
            console.log("rhw took:", (Date.now() - startT1), "ms");

            const startT2 = Date.now();
            recursiveHelloWorldCallback(times, () => {
                console.log("rhwcb took:", (Date.now() - startT2), "ms");
            });
        });
    });
};

const recursivePlain = (max = 1000, cb = null, step = 1) => {
    
    if(step > max){
        return cb();
    }

    step += 1;
    process.nextTick(() => {
        recursiveHelloWorld(max, cb, step);
    });
};

const recursiveHelloWorld = (max = 1000, cb = null, step = 1) => {

    if(step > max){
        return cb();
    }

    addon.hello("hi ");

    step += 1;
    process.nextTick(() => {
        recursiveHelloWorld(max, cb, step);
    });
};

const recursiveHelloWorldCallback = (max = 1000, cb = null, step = 1) => {

    if(step > max){
        return cb();
    }

    return addon.helloCall(true, {}, () => {
        step += 1;
        return recursiveHelloWorldCallback(max, cb, step);
    });
};

module.exports = {run, runBench};