require 'indigo_compute'
require 'beefcake'
require_relative './lib/indigo/compute.rb'

puts '-----'
result = Indigo::Compute.full_sweep(arg: 'hello')
puts "result: #{result}"
puts '-----'
