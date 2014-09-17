#ifndef ruby_compute_h__
#define ruby_compute_h__

#include <string>
#include <ruby.h>
#include <stdarg.h>
#include "compute.h"

#define WRAP(func, argType)                             \
  VALUE func##_ruby_wrapper(VALUE self, VALUE args) {   \
    return encode(func(decode<argType>(args)));         \
  }

#define INSTALL(module, rubyName, func)                                 \
  rb_define_singleton_method(module, rubyName, (VALUE(*)(ANYARGS))func##_ruby_wrapper, 1)

template<class T>
inline T decode(VALUE args) {
  char *argsBuf = RSTRING_PTR(args);
  std::string argsStr(argsBuf, RSTRING_LEN(args));
  T pbArgs;
  pbArgs.ParseFromString(argsStr);
  return pbArgs;
}

template<class T>
inline VALUE encode(T pbResult) {
  std::string resultStr;
  pbResult.SerializeToString(&resultStr);
  const char *resultBuf = resultStr.c_str();
  return rb_str_new(resultBuf, resultStr.size());
}

VALUE define_module(const char *longName) {
  char names[1024];
  strcpy(names, longName);
  char *name;
  VALUE parent = Qnil;

  name = strtok(names, ":");
  do {
    parent = (parent == Qnil) ? rb_define_module(name) : rb_define_module_under(parent, name);
  } while (NULL != (name = strtok(NULL, ":")));

  return parent;
}

#endif // ruby_compute_h__
