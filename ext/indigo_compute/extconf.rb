require 'mkmf'
extension_name = 'indigo_compute'
dir_config(extension_name)
have_library('protobuf')
create_makefile(extension_name)
