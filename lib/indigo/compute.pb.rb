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

        class PerfTestArgs
          include Beefcake::Message
        end

        class PerfTestResult
          include Beefcake::Message
        end

        class FullSweepArgs
          required :arg, :string, 1
        end

        class FullSweepResult
          required :result, :string, 1
        end

        class PerfTestArgs
          optional :xBytes, :bytes, 1
          optional :yBytes, :bytes, 2
          repeated :xDoubles, :double, 3
          repeated :yDoubles, :double, 4
        end

        class PerfTestResult
          required :result, :double, 1
        end
      end
    end
  end
end
