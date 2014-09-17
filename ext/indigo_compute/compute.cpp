#include <stdio.h>
#include "compute.h"

using namespace std;
using namespace ib::ffi::compute::v3_3_0;

FullSweepResult fullSweep(const FullSweepArgs& args) {
  FullSweepResult result;
  result.set_result("you said: " + args.arg());
  return result;
}

PerfTestResult perfTest(const PerfTestArgs& args) {
  PerfTestResult result;
  result.set_result(1);
  return result;
}
