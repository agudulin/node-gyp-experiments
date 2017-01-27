#include <node.h>

using namespace v8;

void getName(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  HandleScope scope(isolate);

  if (args.Length() < 1) {
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "kanye"));
  } else {
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "west"));
  }
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "getName", getName);
}

NODE_MODULE(test, init);
