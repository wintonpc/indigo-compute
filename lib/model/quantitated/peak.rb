require 'common/model/embedded_document'
class Peak
  include Mongoid::Document
  include EmbeddedDocument

  field :peak_index, :type => Float
  field :start_index, :type => Float
  field :start_time, :type => Float
  field :start_inten, :type => Float
  field :start_base_int, :type => Float  
  field :end_index, :type => Float
  field :end_time, :type => Float
  field :end_inten, :type => Float
  field :end_base_int, :type => Float
  field :apex_index, :type => Float
  field :apex_time, :type => Float
  field :apex_inten, :type => Float
  field :baseline_intercept, :type => Float
  field :baseline_slope, :type => Float
  field :height, :type => Float
  field :area, :type => Float
  field :prob, :type => Float
  field :nls_amp, :type => Float
  field :nls_mu, :type => Float
  field :nls_sig, :type => Float
  field :nls_tau, :type => Float
  field :fitted_start, :type => Float
  field :fitted_end, :type => Float
  field :fitted_apex, :type => Float
  field :fitted_coverage, :type => Float
  field :smooth_emg_area_diff, :type => Float
  field :saturated, :type => Boolean
  field :quality_score, :type => Float
  field :reprocess, :type => Boolean
  field :better_sig, :type => Float
  field :better_tau, :type => Float
end