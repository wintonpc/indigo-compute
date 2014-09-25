require 'mongoid'

class ConvertedSample
  include Mongoid::Document

  belongs_to :batch
  field :name, type: String
  field :unique_id, :type => String
  embeds_many :converted_chromatograms

end