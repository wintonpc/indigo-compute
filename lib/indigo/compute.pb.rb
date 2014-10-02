## Generated from ib/ffi/compute/v3_3_0/compute.proto for ib.ffi.compute.v3_3_0
require "beefcake"

module Ib
  module Ffi
    module Compute
      module V3_3_0

        class FullSweepArgs
          include Beefcake::Message
        end

        class FullSweepResult
          include Beefcake::Message
        end

        class AssayConfiguration
          include Beefcake::Message
        end

        class QuantitatedSample
          include Beefcake::Message
        end

        class QuantitatedCompound
          include Beefcake::Message
        end

        class QuantitatedChromatogram
          include Beefcake::Message
        end

        class ConvertedSample
          include Beefcake::Message
        end

        class ConvertedChromatogram
          include Beefcake::Message
        end

        class FullSweepArgs
          required :assayConfig, AssayConfiguration, 1
          repeated :convertedSamples, ConvertedSample, 2
        end

        class FullSweepResult
          repeated :quantitatedSamples, QuantitatedSample, 1
        end

        class AssayConfiguration
          required :name, :string, 1
        end

        class QuantitatedSample
          required :id, :string, 1
          required :name, :string, 2
          required :unique_id, :string, 3
          repeated :quantitatedCompounds, QuantitatedCompound, 4
        end

        class QuantitatedCompound
          required :id, :string, 1
          required :name, :string, 2
          repeated :quantitatedChromatograms, QuantitatedChromatogram, 3
        end

        class QuantitatedChromatogram
          required :id, :string, 1
          required :name, :string, 2
        end

        class ConvertedSample
          required :id, :string, 1
          required :unique_id, :string, 2
          repeated :convertedChromatograms, ConvertedChromatogram, 3
        end

        class ConvertedChromatogram
          required :id, :string, 1
          optional :precursor, :double, 2
          required :product, :double, 3
          required :polarity, :string, 4
          optional :collisionEnergy, :double, 5
        end
      end
    end
  end
end
