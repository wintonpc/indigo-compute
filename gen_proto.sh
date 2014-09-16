#!/bin/bash

protoc --cpp_out ./ext/indigo_compute --proto_path=protos protos/ib/ffi/compute/v3_3_0/compute.proto

BEEFCAKE_NAMESPACE=Ib::Ffi::Compute::V3_3_0 protoc --beefcake_out ./lib/indigo --proto_path=protos protos/ib/ffi/compute/v3_3_0/compute.proto
