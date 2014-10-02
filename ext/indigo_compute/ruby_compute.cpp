#include "ruby_compute.h"

WRAP(fullSweep, ib::ffi::compute::v3_3_0::FullSweepArgs);

extern "C" void Init_indigo_compute() {
  VALUE native = define_module("Indigo::Compute::Native");
  INSTALL(native, "full_sweep", fullSweep);
}
