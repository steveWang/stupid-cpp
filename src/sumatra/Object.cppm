module;

#include <cstddef>
#include <format>
#include <memory>
#include <string>

export module Object;

export class Object {
 public:
  Object() {}
  Object(Object* o) : Object(o->data_) {
    delete o;
  }
  Object(std::shared_ptr<void> data) : data_(data) {}

  virtual size_t hashCode() const {
    return static_cast<int>(reinterpret_cast<size_t>(data_.get()));
  }

  virtual std::string toString() const {
    if (data_ == nullptr) {
      return "null";
    }
    return std::format("{}#{:0x}", typeid(this).name(), hashCode());
  }

  virtual bool equals(const Object& o) const {
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
