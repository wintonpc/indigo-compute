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

      trace_times = {}
      trace_intensities = {}

      bench(:load_traces) do
        ConvertedTrace.where(batch_id: batch_id).each do |ct|
          chrom_id = ct.converted_chromatogram_id.to_s
          trace_times[chrom_id] = ct.times
          trace_intensities[chrom_id] = ct.intensities
        end
      end

      converted_samples = bench(:load_samples) { ConvertedSample.where(batch_id: batch_id) }
      samps = bench(:to_pb) { converted_samples_to_pbs(converted_samples) }

      ac = Pb::AssayConfiguration.new(name: 'fake')
      msg = Pb::FullSweepArgs.new(assay_config: ac, converted_samples: samps)
      encoded_request = bench(:encode) { msg.encode.to_s }
      encoded_result, *traces =
          bench(:native_full_sweep) { Indigo::Compute::Native.full_sweep(encoded_request, trace_times, trace_intensities) }
      result = bench(:decode) { Pb::FullSweepResult.decode(encoded_result) }
      puts "got result!"
      dump_result(result, traces)
    end

    def self.converted_samples_to_pbs(converted_samples)
      converted_samples.map do |cs|
        pbs = converted_sample_to_pb(cs)
        pbs.converted_chromatograms = cs.converted_chromatograms.map do |cc|
          # print '.'
          pbc = converted_chromatogram_to_pb(cc)
          # trace_times[cc.id.to_s] = cc.converted_trace.times.data
          # trace_intensities[cc.id.to_s] = cc.converted_trace.intensities.data
          pbc
        end
        pbs
      end
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

    def self.dump_result(result, traces)
      full_times, plot_times, raw, smooth, global_baseline, plot = traces
      qsamps = result.quantitated_samples || []
      puts "QuantitatedSamples (#{qsamps.size})"
      qsamps.each do |qs|
        puts "  QuantSample #{qs.unique_id} (#{qs.id})"
        qcomps = qs.quantitated_compounds || []
        puts "    QuantitatedCompounds (#{qcomps.size})"
        qcomps.each do |qcomp|
          puts "      QuantCompound #{qcomp.name}"
          qcomp.quantitated_chromatograms.each do |qchrom|
            puts "        QuantChromatogram #{qchrom.name}"
            puts "          full_times: #{full_times[qchrom.id].size}"
          end
        end
      end
    end

    def self.bench(name)
      start = Time.now
      begin
        yield
      ensure
        stop = Time.now
        puts "#{name}: #{stop - start} seconds"
      end
    end
  end
end


