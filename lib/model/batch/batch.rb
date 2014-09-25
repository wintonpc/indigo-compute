require 'mongoid'
class Batch
  include Mongoid::Document
  include Mongoid::Timestamps

  has_many :converted_samples
  has_many :quantitated_samples

end