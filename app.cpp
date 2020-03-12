// addon_src.cc
#include <node.h>
#include "other.h"

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Value;

void test_function(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();

    // Run other function
    other_function();

	args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world", NewStringType::kNormal).ToLocalChecked());
}

void Initialize(Local<Object> exports) {
	NODE_SET_METHOD(exports, "test_function", test_function);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
