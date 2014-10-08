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
          required :assay_config, AssayConfiguration, 1
          repeated :converted_samples, ConvertedSample, 2
        end

        class FullSweepResult
          repeated :quantitated_samples, QuantitatedSample, 1
        end

        class AssayConfiguration
          required :name, :string, 1
        end

        class QuantitatedSample
          required :id, :string, 1
          required :name, :string, 2
          required :unique_id, :string, 3
          repeated :quantitated_compounds, QuantitatedCompound, 4
        end

        class QuantitatedCompound
          required :id, :string, 1
          required :name, :string, 2
          repeated :quantitated_chromatograms, QuantitatedChromatogram, 3
        end

        class QuantitatedChromatogram
          required :id, :string, 1
          required :name, :string, 2
        end

        class ConvertedSample
          required :id, :string, 1
          required :unique_id, :string, 2
          repeated :converted_chromatograms, ConvertedChromatogram, 3
        end

        class ConvertedChromatogram
          required :id, :string, 1
          optional :precursor, :double, 2
          required :product, :double, 3
          required :polarity, :string, 4
          optional :collision_energy, :double, 5
        end
      end
    end
  end
end
