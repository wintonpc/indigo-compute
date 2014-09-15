// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ib/ffi/compute/v1/compute.proto

#ifndef PROTOBUF_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto__INCLUDED
#define PROTOBUF_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace ib {
namespace ffi {
namespace compute {
namespace v1 {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
void protobuf_AssignDesc_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
void protobuf_ShutdownFile_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();

class FullSweepArgs;
class FullSweepResult;

// ===================================================================

class FullSweepArgs : public ::google::protobuf::Message {
 public:
  FullSweepArgs();
  virtual ~FullSweepArgs();
  
  FullSweepArgs(const FullSweepArgs& from);
  
  inline FullSweepArgs& operator=(const FullSweepArgs& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const FullSweepArgs& default_instance();
  
  void Swap(FullSweepArgs* other);
  
  // implements Message ----------------------------------------------
  
  FullSweepArgs* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const FullSweepArgs& from);
  void MergeFrom(const FullSweepArgs& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string arg = 1;
  inline bool has_arg() const;
  inline void clear_arg();
  static const int kArgFieldNumber = 1;
  inline const ::std::string& arg() const;
  inline void set_arg(const ::std::string& value);
  inline void set_arg(const char* value);
  inline void set_arg(const char* value, size_t size);
  inline ::std::string* mutable_arg();
  inline ::std::string* release_arg();
  
  // @@protoc_insertion_point(class_scope:ib.ffi.compute.v1.FullSweepArgs)
 private:
  inline void set_has_arg();
  inline void clear_has_arg();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* arg_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
  friend void protobuf_AssignDesc_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
  friend void protobuf_ShutdownFile_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
  
  void InitAsDefaultInstance();
  static FullSweepArgs* default_instance_;
};
// -------------------------------------------------------------------

class FullSweepResult : public ::google::protobuf::Message {
 public:
  FullSweepResult();
  virtual ~FullSweepResult();
  
  FullSweepResult(const FullSweepResult& from);
  
  inline FullSweepResult& operator=(const FullSweepResult& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const FullSweepResult& default_instance();
  
  void Swap(FullSweepResult* other);
  
  // implements Message ----------------------------------------------
  
  FullSweepResult* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const FullSweepResult& from);
  void MergeFrom(const FullSweepResult& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string result = 1;
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline const ::std::string& result() const;
  inline void set_result(const ::std::string& value);
  inline void set_result(const char* value);
  inline void set_result(const char* value, size_t size);
  inline ::std::string* mutable_result();
  inline ::std::string* release_result();
  
  // @@protoc_insertion_point(class_scope:ib.ffi.compute.v1.FullSweepResult)
 private:
  inline void set_has_result();
  inline void clear_has_result();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* result_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
  friend void protobuf_AssignDesc_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
  friend void protobuf_ShutdownFile_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto();
  
  void InitAsDefaultInstance();
  static FullSweepResult* default_instance_;
};
// ===================================================================


// ===================================================================

// FullSweepArgs

// required string arg = 1;
inline bool FullSweepArgs::has_arg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FullSweepArgs::set_has_arg() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FullSweepArgs::clear_has_arg() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FullSweepArgs::clear_arg() {
  if (arg_ != &::google::protobuf::internal::kEmptyString) {
    arg_->clear();
  }
  clear_has_arg();
}
inline const ::std::string& FullSweepArgs::arg() const {
  return *arg_;
}
inline void FullSweepArgs::set_arg(const ::std::string& value) {
  set_has_arg();
  if (arg_ == &::google::protobuf::internal::kEmptyString) {
    arg_ = new ::std::string;
  }
  arg_->assign(value);
}
inline void FullSweepArgs::set_arg(const char* value) {
  set_has_arg();
  if (arg_ == &::google::protobuf::internal::kEmptyString) {
    arg_ = new ::std::string;
  }
  arg_->assign(value);
}
inline void FullSweepArgs::set_arg(const char* value, size_t size) {
  set_has_arg();
  if (arg_ == &::google::protobuf::internal::kEmptyString) {
    arg_ = new ::std::string;
  }
  arg_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* FullSweepArgs::mutable_arg() {
  set_has_arg();
  if (arg_ == &::google::protobuf::internal::kEmptyString) {
    arg_ = new ::std::string;
  }
  return arg_;
}
inline ::std::string* FullSweepArgs::release_arg() {
  clear_has_arg();
  if (arg_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = arg_;
    arg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// FullSweepResult

// required string result = 1;
inline bool FullSweepResult::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FullSweepResult::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FullSweepResult::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FullSweepResult::clear_result() {
  if (result_ != &::google::protobuf::internal::kEmptyString) {
    result_->clear();
  }
  clear_has_result();
}
inline const ::std::string& FullSweepResult::result() const {
  return *result_;
}
inline void FullSweepResult::set_result(const ::std::string& value) {
  set_has_result();
  if (result_ == &::google::protobuf::internal::kEmptyString) {
    result_ = new ::std::string;
  }
  result_->assign(value);
}
inline void FullSweepResult::set_result(const char* value) {
  set_has_result();
  if (result_ == &::google::protobuf::internal::kEmptyString) {
    result_ = new ::std::string;
  }
  result_->assign(value);
}
inline void FullSweepResult::set_result(const char* value, size_t size) {
  set_has_result();
  if (result_ == &::google::protobuf::internal::kEmptyString) {
    result_ = new ::std::string;
  }
  result_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* FullSweepResult::mutable_result() {
  set_has_result();
  if (result_ == &::google::protobuf::internal::kEmptyString) {
    result_ = new ::std::string;
  }
  return result_;
}
inline ::std::string* FullSweepResult::release_result() {
  clear_has_result();
  if (result_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = result_;
    result_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace compute
}  // namespace ffi
}  // namespace ib

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ib_2fffi_2fcompute_2fv1_2fcompute_2eproto__INCLUDED
