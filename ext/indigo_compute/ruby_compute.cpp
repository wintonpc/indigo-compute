#include "ruby_compute.h"

VALUE Indigo = Qnil;
VALUE Compute = Qnil;
VALUE Native = Qnil;

WRAP(fullSweep, ib::ffi::compute::v3_3_0::FullSweepArgs);

extern "C" void Init_indigo_compute() {
  Indigo = rb_define_module("Indigo");
  Compute = rb_define_module_under(Indigo, "Compute");
  Native = rb_define_module_under(Compute, "Native");
  INSTALL(Native, "full_sweep", fullSweep);
}

VALUE perf_test(VALUE self, VALUE args) {
  return Qnil;
}
