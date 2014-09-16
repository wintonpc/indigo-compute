require 'indigo_compute'
require_relative './compute.pb.rb'

FullSweepArgs = Ib::Ffi::Compute::V3_3_0::FullSweepArgs
FullSweepResult = Ib::Ffi::Compute::V3_3_0::FullSweepResult

module Indigo
  module Compute
    def self.full_sweep(arg_hash)
      FullSweepResult.decode(Native::full_sweep(FullSweepArgs.new(arg_hash).encode.to_s)).result
    end
  end
end


