# C++ ABI Node.js Addon Hello World

## Info

- a simple parameter hello world example
- a more complex async worker hello world example
- build in the new Node.js [N-API](https://nodejs.org/api/n-api.html) (ABI)
- using the C++ wrapper [node-addon-api](https://github.com/nodejs/node-addon-api)

## Requires

- Node.js >= `8.6.0`
- yarn `npm i -g yarn`
- CPP compiler like gcc

## Install & Run

- `yarn` # make sure that node-gyp installation succeeds
- `yarn configure` # prepares MAKE configuration
- `yarn build` # builds native addon to /build
- `yarn start` # runs Javascript that executes native addon's functions

## Structure

- `/lib/*` javascript source
- `/src/*` C++ native addon source
- `./binding.gyp` describes addon configuration for node-gyp
- `./addon.js` uses bindings module to export native addon
- `./index.js` requires javascript version of addon and executes