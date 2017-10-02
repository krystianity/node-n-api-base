// callme.cc
#include "napi.h"

#include <map>

namespace hello {

    typedef std::map<char const*, char const *> hashmap_type;

    //AsyncWorker is an abstract helper class for thread-pooled tasks
    class HelloWorker : public Napi::AsyncWorker {

    public:

        HelloWorker(Napi::Function callback) : AsyncWorker(callback){}

        bool _succeed;
        
    protected:
        
        //called when first in queue and dispatched in thread
        //does not run in javascript context, therefore Env() cannot be used
        //therefore we cannot use Napi::Object to store result data
        void Execute() override {

            if(!_succeed){
                SetError("Hello World Error");
                return;
            }

            //only accessing the std::map here
            _result["zero"] = "ABI";
            _result["one"] = "cool";
            _result["two"] = "awesome";
            _result["three"] = "super";
        }

    private:

        hashmap_type _result;

        Napi::Object MapToObject(hashmap_type __map){

            auto env = Env();
            auto result = Napi::Object::New(env);

            for(auto i = __map.begin(); i != __map.end(); i++){
                result.Set(i->first, Napi::String::New(env, i->second));
            }

            return result;
        }

        //called when Execute() does not call SetError()
        void OnOK() override {
            
            Callback().MakeCallback(Receiver().Value(), std::initializer_list<napi_value>{
                Env().Null(),
                MapToObject(_result)
            });
        }
    };

    void RunCallback(const Napi::CallbackInfo& info){

        auto succeed = info[0].As<Napi::Boolean>();
        auto data = info[1];
        auto callback = info[2].As<Napi::Function>();

        auto worker = new HelloWorker(callback);
        worker->Receiver().Set("data", data);
        worker->_succeed = succeed;
        worker->Queue();
    }

    Napi::Function InitHelloWorldCallback(Napi::Env env){
        return Napi::Function::New(env, RunCallback);
    }
} //namespace hello