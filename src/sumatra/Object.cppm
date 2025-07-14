module;

#include <cstddef>
#include <format>
#include <memory>
#include <string>

export module Object;

export class Object {
 public:
  Object() = default;
  Object(std::shared_ptr<void> data) : data_(data) {}

  virtual size_t hashCode() const {
    return static_cast<int>(reinterpret_cast<size_t>(this));
  }

  virtual std::string toString() const {
    return std::format("{}#{:0x}", typeid(this).name(), hashCode());
  }

  bool equals(const Object& o) const {
    return *this == o;
  }

  bool operator==(const Object& o) const {
    if (data_ == nullptr) {
      return o.data_ == nullptr;
    }
    return data_ == o.data_;
  }

 protected:
  std::shared_ptr<void> data_;
};

export Object null;
