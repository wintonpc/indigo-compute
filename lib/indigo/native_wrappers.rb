module NativeWrappers
  def wrap(method_module, method_name, result_type)
    define_singleton_method(method_name) do |arg_obj|
      result_type.decode(method_module.method(method_name).call(arg_obj.encode.to_s))
    end
  end
end
