require 'common/model/quantitated/quantitated_compound'

class QuantitatedSample
  include Mongoid::Document
  include Mongoid::Timestamps

  belongs_to :batch
  field :name, :type => String
  field :unique_id, :type => String
  has_many :quantitated_compounds, :dependent => :destroy
end