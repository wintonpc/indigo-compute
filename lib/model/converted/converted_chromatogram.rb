require 'mongoid'

class ConvertedChromatogram
  include Mongoid::Document
  embedded_in :converted_sample

  field :precursor, type: Float
  field :product, type: Float
  field :polarity, type: String
  field :collision_energy, type: Float
  has_one :converted_trace
end