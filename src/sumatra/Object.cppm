module;

#include <cstddef>
#include <format>
#include <memory>
#include <string>

export module Object;

import base;

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

  virtual boolean equals(const Object& o) const {
    return boolean(*this == o);
  }

  boolean operator==(const Object& o) const {
    if (data_ == nullptr) {
      return boolean(o.data_ == nullptr);
    }
    return boolean(data_ == o.data_);
  }

 protected:
  std::shared_ptr<void> data_;
};

export Object null;
