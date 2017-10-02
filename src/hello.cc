// hello.cc
#include "napi.h"

namespace hello {

    Napi::String Method(const Napi::CallbackInfo& info){
        
        auto parameter = info[0].As<Napi::String>();

        std::string returnValue = "world";
        if(!parameter.IsUndefined()){
            returnValue = parameter.Utf8Value() + returnValue;
        }

        return Napi::String::New(info.Env(), returnValue);
    }

    Napi::Function InitHelloWorld(Napi::Env env){
        return Napi::Function::New(env, Method);
    }
} //namespace hello