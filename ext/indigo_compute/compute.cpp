#include <stdio.h>
#include "compute.h"

using namespace std;
using namespace ib::ffi::compute::v1;

FullSweepResult fullSweep(const FullSweepArgs& args) {
  FullSweepResult result;
  result.set_result("you said: " + args.arg());
  return result;
}
