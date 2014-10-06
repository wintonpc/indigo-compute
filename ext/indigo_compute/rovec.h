#ifndef rovec_h__
#define rovec_h__

#include <vector>

template<class T>
class rovec {
 public:
  
 rovec()
   : buf((T*)NULL), len(0) {}
  
 rovec(T *buf, unsigned long len)
   : buf(buf), len(len) {}
  
 rovec(const rovec& other)
   : buf(other.buf), len(other.len) {}
  
  unsigned long size() const {
    return len;
  }
  
  rovec<T>& operator= (const rovec<T>& other) {
    this->buf = other.buf;
    this->len = other.len;
    return *this;
  }

  const T& operator[] (unsigned long n) const {
    return buf[n];
  }

  const T *data() const {
    return buf;
  }

  const T *begin() const {
    return buf;
  }

  const T *end() const {
    return buf + len;
  }

 private:
  T *buf;
  unsigned long len;

};

#endif // rovec_h__
