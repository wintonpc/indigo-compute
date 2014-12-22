#ifndef ruby_compute_h__
#define ruby_compute_h__

#include <stdio.h>
#include <string>
#include <ruby.h>
#include <stdarg.h>
#include "compute.h"

#define WRAP(func, argType)                             \
  VALUE func##_ruby_wrapper(VALUE self, VALUE args) {   \
    return encode(func(decode<argType>(args)));         \
  }

#define INSTALL(module, rubyName, func, arity)                                \
  rb_define_singleton_method(module, rubyName, (VALUE(*)(ANYARGS))func##_ruby_wrapper, arity)

template<class T>
inline T decode(VALUE args) {
  char *argsBuf = RSTRING_PTR(args);
  std::string argsStr(argsBuf, RSTRING_LEN(args));
  T pbArgs;
  pbArgs.ParseFromString(argsStr);
  return pbArgs;
}

template<class T>
inline VALUE encode(T pbResult) {
  std::string resultStr;
  pbResult.SerializeToString(&resultStr);
  const char *resultBuf = resultStr.c_str();
  return rb_str_new(resultBuf, resultStr.size());
}

inline VALUE define_module(const char *longName) {
  char names[1024];
  strcpy(names, longName);
  char *name;
  VALUE parent = Qnil;

  name = strtok(names, ":");
  do {
    parent = (parent == Qnil) ? rb_define_module(name) : rb_define_module_under(parent, name);
  } while (NULL != (name = strtok(NULL, ":")));

  return parent;
}

inline int co_hash_to_map(VALUE key, VALUE val, VALUE map) {
  //printf("co_hash_to_map(%s)\n", RSTRING_PTR(key));
  int byteCount = RSTRING_LEN(val);
  char *bytes = RSTRING_PTR(val);
  //printf("  buffer len: %d\n", byteCount);
  double *doubles = (double*)bytes;
  int doubleCount = byteCount / 8;
  (*((FloatsMap*)map))[std::string(RSTRING_PTR(key))] = Floats(doubles, doubleCount);
  //printf("  map[\"%s\"] = doubles(%d)\n", RSTRING_PTR(key), doubleCount);
  return ST_CONTINUE;
}

inline FloatsMap hash_to_map(const VALUE& hash) {
  FloatsMap map;
  printf("rb_hash_foreach\n");
  rb_hash_foreach(hash, (int(*)(ANYARGS))co_hash_to_map, (VALUE)&map);
  printf("rb_hash_foreach: done\n");
  return map;
}

inline VALUE map_to_hash(FloatsMap map) {
  VALUE hash = rb_hash_new();
  for (auto& pair : map) {
    printf("map_to_hash %s, %d points\n", pair.first.c_str(), (int)pair.second.size());
    for (double d : pair.second.data())
      printf("%f\n", d);
    VALUE val = rb_str_new((const char*)pair.second.data(), pair.second.size() * 8);
    printf("got value\n");
    rb_hash_aset(hash, rb_str_new2(pair.first.c_str()), val);
  }
  return hash;
}

#endif // ruby_compute_h__
