require 'mongoid'

class ConvertedTrace
  include Mongoid::Document
  field :converted_chromatogram_id, type: BSON::ObjectId
  field :times, type: BSON::Binary
  field :intensities, type: BSON::Binary
  field :batch_id, type: BSON::ObjectId
end