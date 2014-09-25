class QuantitatedTraces
  include Mongoid::Document

  belongs_to :quantitated_chromatograms
  field :full_times, :type => BSON::Binary
  field :plot_times, :type => BSON::Binary
  field :raw, :type => BSON::Binary
  field :smooth, :type => BSON::Binary
  field :global_baseline, :type => BSON::Binary
  field :plot, :type => BSON::Binary
  field :quantitated_chromatogram_id
  field :batch_id
end