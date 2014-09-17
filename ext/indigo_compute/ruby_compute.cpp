#include "ruby_compute.h"

WRAP(fullSweep, ib::ffi::compute::v3_3_0::FullSweepArgs);
WRAP(perfTest, ib::ffi::compute::v3_3_0::PerfTestArgs);

VALUE perfRaw_ruby_wrapper(VALUE self, VALUE arg) {
  int len = NUM2INT(arg) * 8;
  std::string result(len, 'z');
  return rb_str_new(result.c_str(), len);
}

extern "C" void Init_indigo_compute() {
  VALUE native = define_module("Indigo::Compute::Native");
  INSTALL(native, "full_sweep", fullSweep);
  INSTALL(native, "perf_test", perfTest);
  INSTALL(native, "perf_raw", perfRaw);
}
