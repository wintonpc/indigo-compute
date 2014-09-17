#include <ruby.h>
#include "ruby_compute.h"
#include "compute.h"
#include <stdio.h>

using namespace std;
using namespace ib::ffi::compute::v3_3_0;

#define INSTALL(name)                                                   \
  rb_define_singleton_method(Native, #name, (VALUE(*)(ANYARGS))name, 1)

#define DEFINE(name, impl, argType)                             \
  VALUE name(VALUE self, VALUE args) {                          \
    return encode(impl(decode<argType>(args)));                 \
  }
  

namespace ruby {

  VALUE Indigo = Qnil;
  VALUE Compute = Qnil;
  VALUE Native = Qnil;

  extern "C" void Init_indigo_compute() {
    Indigo = rb_define_module("Indigo");
    Compute = rb_define_module_under(Indigo, "Compute");
    Native = rb_define_module_under(Compute, "Native");
    INSTALL(full_sweep);
  }

  DEFINE(full_sweep, ::fullSweep, FullSweepArgs);

  VALUE perf_test(VALUE self, VALUE args) {
    return Qnil;
  }
}
