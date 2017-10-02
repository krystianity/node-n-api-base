{
    "targets": [
        {
            "target_name": "addon",
            "cflags_cc": [
                "-std=c++11"
            ],
            "cflags_cc!": [
                "-fno-exceptions",
                "-fno-rtti"    
            ],
            "sources": [ 
                "<!@(ls -1 src/*.cc)"
            ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            "dependencies": [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            "defines": [
                "NAPI_DISABLE_CPP_EXCEPTIONS"
            ]
        }
    ]
}