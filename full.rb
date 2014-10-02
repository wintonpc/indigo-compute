$LOAD_PATH << File.join(File.dirname(__FILE__), 'lib')
require 'indigo/compute'
require 'model/batch/batch'
require 'mongoid'
ENV['RACK_ENV'] = 'development'
Mongoid.load!('config/mongoid.yml')

Mongoid.override_database('ascent_production_cdc')
batch_id = Batch.all.first.id
puts "batch: #{batch_id}"
Indigo::Compute.full_sweep(batch_id)
