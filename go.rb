require 'indigo/compute'

args = Ib::Ffi::Compute::V3_3_0::FullSweepArgs.new(arg: 'hello')
puts Indigo::Compute.full_sweep(args).result
