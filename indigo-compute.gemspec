Gem::Specification.new do |s|
  s.name          = 'indigo-compute'
  s.version       = '0.0.4'
  s.summary       = 'Compute for indigo apps'
  s.author        = 'Peter Winton'
  s.email         = %w(info@indigobio.com)
  s.description   = 'prototype'
  s.homepage      = 'http://www.indigobio.com'

  s.files = Dir.glob('ext/**/*.{h,cpp,cc,rb}') + Dir.glob('lib/**/*.rb')

  s.extensions << 'ext/indigo_compute/extconf.rb'
  s.add_development_dependency 'rake-compiler', '~> 0'
end
