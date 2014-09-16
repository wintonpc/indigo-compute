#ifndef compute_h__
#define compute_h__

#include <string>
#include "ib/ffi/compute/v3_3_0/compute.pb.h"

ib::ffi::compute::v3_3_0::FullSweepResult
fullSweep(const ib::ffi::compute::v3_3_0::FullSweepArgs& args);

#endif // compute_h__
