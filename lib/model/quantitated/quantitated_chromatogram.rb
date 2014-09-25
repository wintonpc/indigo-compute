require 'common/model/quantitated/quantitated_compound'
require 'common/model/assay_configuration/preview_chromatogram'

require 'common/model/quantitated/peak'
require 'common/model/quantitated/global_trace'
require 'common/model/quantitated/smooth_trace'
require 'common/model/quantitated/emg_trace'
require 'common/model/quantitated/raw_trace'
require 'common/model/embedded_document'

class QuantitatedChromatogram
  include Mongoid::Document
  include EmbeddedDocument

  embedded_in :quantitated_compound
  embedded_in :preview_chromatogram
  field :name, :type => String
  field :is_manually_modified, :type => Boolean
  field :expected_rt, :type => Float
  field :smooth_snr, :type => Float
  field :max_rt_tolerance_intensity, :type => Float
  field :filter_tsz, :type => Float
  field :potential_peaks, :type => Hash

  embeds_one :peak
  has_one :trace_times
  has_one :raw_trace
  has_one :emg_trace
  has_one :global_trace
  has_one :smooth_trace
  has_one :quantitated_traces
end