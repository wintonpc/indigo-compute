require 'indigo_compute'
require_relative './native_wrappers'
require_relative './compute.pb'
require 'model/converted/converted_sample'
require 'model/converted/converted_chromatogram'
require 'model/converted/converted_trace'

Pb = Ib::Ffi::Compute::V3_3_0

module Indigo
  module Compute

    def self.full_sweep(batch_id)

      samps, trace_times, trace_intensities = converted_samples_to_pbs(ConvertedSample.where(batch_id: batch_id))

      ac = Pb::AssayConfiguration.new(name: 'fake')
      msg = Pb::FullSweepArgs.new(assayConfig: ac, convertedSamples: samps)
      result = Pb::FullSweepResult.decode(Indigo::Compute::Native.full_sweep(msg.encode, trace_times, trace_intensities))
      puts "got result: #{result}"
    end

    def self.converted_samples_to_pbs(converted_samples)

      trace_times = {}
      trace_intensities = {}

      samps = converted_samples.map do |cs|
        pbs = converted_sample_to_pb(cs)
        pbs.convertedChromatograms = cs.converted_chromatograms.map do |cc|
          pbc = converted_chromatogram_to_pb(cc)
          trace_times[cc.id.to_s] = cc.converted_trace.times
          trace_intensities[cc.id.to_s] = cc.converted_trace.intensities
          pbc
        end
        pbs
      end

      [samps, trace_times, trace_intensities]

    end

    def self.converted_sample_to_pb(s)
      Pb::ConvertedSample.new(id: s.id.to_s, unique_id: s.unique_id)
    end

    def self.converted_chromatogram_to_pb(c)
      Pb::ConvertedChromatogram.new(
          id: c.id.to_s,
          precursor: c.precursor,
          product: c.product,
          polarity: c.polarity,
          collision_energy: c.collision_energy
      )
    end
  end
end


