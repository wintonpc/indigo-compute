```
sudo apt-get install protobuf-c-compiler libprotobuf-dev
git clone git@github.com:wintonpc/indigo-compute.git
cd indigo-compute
bundle install
./gen_proto.sh
gem build indigo-compute.gemspec
gem install indigo-compute-*.gem
ruby go.rb     # smoke test
ruby perf.rb   # performance test
```
