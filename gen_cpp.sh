#!/bin/bash

protoc --cpp_out ./ext/indigo_compute --proto_path=protos protos/ib/ffi/compute/v1/compute.proto
