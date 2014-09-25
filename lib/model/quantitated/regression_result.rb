require 'common/model/embedded_document'
class RegressionResult
  include Mongoid::Document
  include EmbeddedDocument

  embedded_in :quantitated_compound
  field :performed_regression, :type => Boolean
  field :successful_regression, :type => Boolean
  field :found_concentration, :type => Boolean
  field :calculated_concentration, :type => Float
end