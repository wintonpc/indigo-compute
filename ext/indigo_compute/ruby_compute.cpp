#include <ruby.h>
#include "ruby_compute.h"
#include "compute.h"
#include "protobuf/ib/ffi/compute/v1/compute.pb.h"

using namespace std;
using namespace ib::ffi::compute::v1;

VALUE Indigo = Qnil;
VALUE Compute = Qnil;

void Init_indigo_compute() {
  Indigo = rb_define_module("Indigo");
  Compute = rb_define_module_under(Indigo, "Compute");
  rb_define_singleton_method(Compute, "full_sweep", (VALUE(*)(ANYARGS))ruby_fullSweep, 1);
}

VALUE ruby_fullSweep(VALUE self, VALUE args) {
  char *argsBuf = RSTRING_PTR(args);
  string argsStr(argsBuf, RSTRING_LEN(args));
  FullSweepArgs pbArgs;
  pbArgs.ParseFromString(argsStr);

  FullSweepResult pbResult = fullSweep(pbArgs);

  string resultStr;
  pbResult.SerializeToString(&resultStr);
  const char *resultBuf = resultStr.c_str();
  rb_str_new(resultBuf, resultStr.size());
}