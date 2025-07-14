module;

#include <format>
#include <memory>
#include <string>

export module Object;

export class Object {
 public:
  Object() = default;
  Object(std::shared_ptr<void> data) : data_(data) {}

  virtual int hashCode() const {
    return static_cast<int>(reinterpret_cast<long long>(this));
  }

  virtual std::string toString() const {
    return std::format("%s#%x", typeid(this).name(), hashCode());
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
