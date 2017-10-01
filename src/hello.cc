// hello.cc
#include "napi.h"

namespace hello {

    Napi::String Method(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();
        return Napi::String::New(env, "world");
    }

    Napi::Function InitHelloWorld(Napi::Env env){
        Napi::Function hello_function = Napi::Function::New(env, Method);
        return hello_function;
    }
} //namespace hello