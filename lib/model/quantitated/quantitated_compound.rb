require 'common/model/quantitated/quantitated_chromatogram'
require 'common/model/quantitated/regression_result'

class QuantitatedCompound
  include Mongoid::Document
  include Mongoid::Timestamps

  belongs_to :quantitated_samples

  field :batch_id, :type => BSON::ObjectId
  field :assay_id, :type => BSON::ObjectId
  field :compute_version, :type => String

  field :name, :type => String
  field :unique_id, :type => String
  field :response, :type => Float
  field :nominal_concentration, :type => Float
  field :report_concentration, :type => Float
  field :deviation, :type => Float
  field :use_record, :type => Boolean
  field :std_dev, :type => Float
  field :view_order, :type => Integer
  field :sample_index, :type => Integer
  field :quantitated_sample_id, :type => BSON::ObjectId

  embeds_one :regression_result
  embeds_many :quantitated_chromatograms
end