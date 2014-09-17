#ifndef ruby_compute_h__
#define ruby_compute_h__

#include <string>
#include <ruby.h>
#include "compute.h"

namespace ruby {

  VALUE full_sweep(VALUE self, VALUE args);
  VALUE perf_test(VALUE self, VALUE args);

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
}

#endif // ruby_compute_h__
