// hello.cc
#include "napi.h"

namespace hello {

    void RunCallback(const Napi::CallbackInfo& info){
        Napi::Env env = info.Env();
        Napi::Function callback = info[0].As<Napi::Function>();
        callback.MakeCallback(env.Global(), {
            Napi::String::New(env, "hello world")
        });
    }

    Napi::Function InitCallMe(Napi::Env env){
        Napi::Function runcallback_function = Napi::Function::New(env, RunCallback);
        return runcallback_function;
    }
} //namespace hello