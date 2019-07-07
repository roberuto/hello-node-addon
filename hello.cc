#include <node.h>

using namespace v8;

//access to argments from js file
void Method(const FunctionCallbackInfo<Value> &args)
{
  //access to scope of js file
  Isolate *isolate = args.GetIsolate();

  //v8 data string type
  Local<String> hello = String::NewFromUtf8(isolate, "Hello World!");

  //return value to js file
  args.GetReturnValue().Set(hello);
}

//export like module.exports
void init(Local<Object> exports)
{
  NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(native_hello, init)