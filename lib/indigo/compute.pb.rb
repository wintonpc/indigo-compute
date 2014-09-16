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

        class FullSweepArgs
          required :arg, :string, 1
        end

        class FullSweepResult
          required :result, :string, 1
        end
      end
    end
  end
end
