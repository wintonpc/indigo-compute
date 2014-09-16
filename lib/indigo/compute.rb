require 'indigo_compute'
require_relative './compute.pb.rb'

module Indigo
  module Compute
    def self.full_sweep(arg_hash)
      FullSweepResult.decode(full_sweep_(FullSweepArgs.new(arg_hash).encode.to_s))
    end
  end
end


