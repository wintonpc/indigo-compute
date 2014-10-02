require 'mkmf'
extension_name = 'indigo_compute'
this_dir = File.dirname(__FILE__)
FileUtils.copy(File.join(this_dir, 'ib/ffi/compute/v3_3_0/compute.pb.cc'), this_dir)
dir_config(extension_name)
have_library('protobuf')
$CPPFLAGS += ' -Wall -Werror -std=c++11'
create_makefile(extension_name)

