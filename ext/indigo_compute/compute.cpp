#include <stdio.h>
#include "compute.h"

using namespace std;
using namespace ib::ffi::compute::v3_3_0;

FullSweepResult fullSweep(const FullSweepArgs& args, const FloatsMap& traceTimes, const FloatsMap& traceIntensities,
                          // out params
                          FloatsMap& fullTimes, FloatsMap& plotTimes, FloatsMap& raw,
                          FloatsMap& smooth, FloatsMap& globalBaseline, FloatsMap& plot) {
  
  printf("fullSweep got converted samples with %d total traces\n", (int)traceTimes.size());

  FullSweepResult result;


  return result;
}
