#ifndef compute_h__
#define compute_h__

#include <map>
#include <vector>
#include <string>
#include "rovec.h"
#include "ib/ffi/compute/v3_3_0/compute.pb.h"

typedef rovec<double> Floats;
typedef std::map<std::string, Floats> FloatsMap;

ib::ffi::compute::v3_3_0::FullSweepResult
fullSweep(const ib::ffi::compute::v3_3_0::FullSweepArgs& args,
          const FloatsMap& traceTimes, const FloatsMap& traceIntensities,
          // out params
          FloatsMap& fullTimes, FloatsMap& plotTimes, FloatsMap& raw,
          FloatsMap& smooth, FloatsMap& globalBaseline, FloatsMap& plot);

#endif // compute_h__
