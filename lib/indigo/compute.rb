require 'indigo_compute'
require_relative './native_wrappers'
require_relative './compute.pb'

Pb = Ib::Ffi::Compute::V3_3_0

module Indigo
  module Compute
    extend NativeWrappers

    wrap Native, :full_sweep, Pb::FullSweepResult
    wrap Native, :perf_test, Pb::PerfTestResult
    
  end
end


