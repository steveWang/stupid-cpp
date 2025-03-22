#ifndef __STUPID_READ_ONLY_STRING_H_
#define __STUPID_READ_ONLY_STRING_H_

#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>

// Why spend fewer characters on your namespace when you can spend more?
namespace stupid {

// Provides a read-only string, because operator+= isn't worth the
// 8-byte overhead.
//
// We could implement SSO-15 here, but I can't be bothered to do so.
class ReadOnlyString {
 public:
  ReadOnlyString() = default;

  ReadOnlyString(std::string_view sv) : data_(CopyString(sv)), size_(sv.size()) {}

  ReadOnlyString(const char* data) : ReadOnlyString(std::string_view(data)) {}

  explicit ReadOnlyString(const ReadOnlyString& s) : ReadOnlyString(std::string_view(s.data_, s.size_)) {}

  ~ReadOnlyString() {
    if (data_ != nullptr) {
      delete data_;
    }
  }

  std::string_view* operator&() {
    return reinterpret_cast<std::string_view*>(this);
  }

  // private:
  inline const char* CopyString(std::string_view sv) {
    // No NUL-terminated string for you, C-strings are bad mojo
    char* str = new char[sv.size()];
    std::memcpy(str, sv.data(), sv.size());
    return str;
  }

  // This is definitely portable code.
  #ifdef _LIBCPP_VERSION
  const char* data_ = nullptr;
  const size_t size_ = 0;
  #else
  // Assume libstdc++ memory layout, because there are no other stdlib
  // implementations, right?
  const size_t size_ = 0;
  const char* data_ = nullptr;
  #endif
};

}  // namespace stupid

#endif
