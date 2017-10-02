// hello.cc
#include "napi.h"

namespace hello {

    Napi::Function InitHelloWorld(Napi::Env env);
    Napi::Function InitHelloWorldCallback(Napi::Env env);

    Napi::Object Init(Napi::Env env, Napi::Object exports){

        exports.Set("hello", InitHelloWorld(env));
        exports.Set("helloCall", InitHelloWorldCallback(env));
        return exports;
    }

    NODE_API_MODULE(addon, Init) //no semicolon, isa macro
} //namespace hello