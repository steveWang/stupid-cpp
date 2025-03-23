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
  constexpr ReadOnlyString() = default;
  constexpr ReadOnlyString(std::string_view sv) : data_(CopyString(sv)) {}
  constexpr ReadOnlyString(const char* data)
      : ReadOnlyString(std::string_view(data)) {}
  explicit ReadOnlyString(const ReadOnlyString& s) : ReadOnlyString(s.data_) {}

  ~ReadOnlyString() {
    if (data_.data() != nullptr) {
      delete data_.data();
    }
  }

  std::string_view* operator&() { return &data_; }

 private:
  inline const std::string_view CopyString(std::string_view sv) {
    // No NUL-terminated string for you, C-strings are bad mojo
    char* str = new char[sv.size()];
    std::memcpy(str, sv.data(), sv.size());
    return std::string_view(str, sv.size());
  }

  std::string_view data_;
};

}  // namespace stupid

#endif
