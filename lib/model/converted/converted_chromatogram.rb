require 'mongoid'

class ConvertedChromatogram
  include Mongoid::Document

  field :precursor, type: Float
  field :product, type: Float
  field :polarity, type: String
  field :collision_energy, type: Float

  embedded_in :converted_sample
  has_one :converted_trace
end