require 'rake/extensiontask'
spec = Gem::Specification.load('indigo-compute.gemspec')
Rake::ExtensionTask.new('indigo_compute', spec) do |ext|
  ext.source_pattern = "*.{c,cc,cpp}"
end
