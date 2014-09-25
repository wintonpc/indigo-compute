require 'indigo_compute'
require_relative './native_wrappers'
require_relative './compute.pb'
require 'model/converted'

Pb = Ib::Ffi::Compute::V3_3_0

module Indigo
  module Compute

    def full_sweep(batch_id)
      ConvertedSample.find(batch_id: batch_id)
    end

  end
end


