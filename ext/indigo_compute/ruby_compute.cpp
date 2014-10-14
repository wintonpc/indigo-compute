#include "ruby_compute.h"
#include "compute.h"

using namespace std;

VALUE fullSweep_ruby_wrapper(VALUE self, VALUE msg, VALUE trace_times, VALUE trace_intensities) {

  Traces quantTraces;
  
  printf("about to decode msg (%d bytes long)\n", (int)RSTRING_LEN(msg));
  ib::ffi::compute::v3_3_0::FullSweepArgs decoded = decode<ib::ffi::compute::v3_3_0::FullSweepArgs>(msg);
  VALUE result = encode(fullSweep(decoded,
                                  hash_to_map(trace_times), hash_to_map(trace_intensities),
                                  quantTraces));

  return rb_ary_new3(7, result,
                     map_to_hash(quantTraces.fullTimes),
                     map_to_hash(quantTraces.plotTimes),
                     map_to_hash(quantTraces.raw),
                     map_to_hash(quantTraces.smooth),
                     map_to_hash(quantTraces.globalBaseline),
                     map_to_hash(quantTraces.plot));
}

extern "C" void Init_indigo_compute() {
  VALUE native = define_module("Indigo::Compute::Native");
  rb_define_singleton_method(native, "full_sweep", (VALUE(*)(ANYARGS))fullSweep_ruby_wrapper, 3);
}
