#ifndef compute_h__
#define compute_h__

#include <string>
#include "protobuf/ib/ffi/compute/v1/compute.pb.h"

ib::ffi::compute::v1::FullSweepResult
fullSweep(const ib::ffi::compute::v1::FullSweepArgs& args);

#endif // compute_h__
