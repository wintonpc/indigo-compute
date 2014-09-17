require 'securerandom'
require 'indigo/compute'

def make_double_bytes(num_doubles)
  (num_doubles * 8 / 32).times.map{SecureRandom.hex}.join
end

# AP 1300 * 100
# CDC 60 * 80,000

m = 10

[{desc: "protobuf", method: ->(args, len){Indigo::Compute.perf_test(args)}},
 {desc: "raw", method: ->(args, len){Indigo::Compute::Native.perf_raw(len)}}].each do |t|
  
  puts "#{t[:desc]}:"
  f = t[:method]
  
  [{name: "ap", n: 1300, len: 100},
   {name: "cdc", n: 60, len: 80000}].each do |s|
    
    xs = make_double_bytes(s[:len])
    ys = make_double_bytes(s[:len])
    
    nm = s[:n] * m

    tStart = Time.now
    nm.times do
      args = Ib::Ffi::Compute::V3_3_0::PerfTestArgs.new(xBytes: xs, yBytes: ys)
      f.call(args, s[:len])
    end
    tEnd = Time.now
    
    elapsed = (tEnd - tStart) * 1000
    
    puts "  #{s[:name]} (#{s[:n]} compounds x #{s[:len]} points): #{s[:n]} calls in #{(elapsed/m).floor}ms, #{(elapsed/nm*1000).floor} microseconds per call"
  end
end
