require 'indigo_compute'
require 'beefcake'
require_relative './lib/compute.pb.rb'

FullSweepArgs = Ib::Ffi::Compute::V1::FullSweepArgs
FullSweepResult = Ib::Ffi::Compute::V1::FullSweepResult

puts '-----'

args = FullSweepArgs.new(arg: "hello")
result = FullSweepResult.decode(Indigo::Compute.full_sweep(args.encode.to_s))
puts "result: #{result.result}"

puts '-----'
