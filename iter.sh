gem uninstall -a indigo-compute &&
rm -f indigo-compute-*.gem &&
rake clean &&
rake compile &&
gem build indigo-compute.gemspec &&
gem install indigo-compute-*.gem &&
bundle exec ruby full.rb
