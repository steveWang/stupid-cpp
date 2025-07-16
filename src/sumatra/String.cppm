module;

#include <memory>
#include <string>
#include <string_view>

export module String;

import base;
import Object;

export class String : public Object {
 public:
  String() : Object(
      reinterpret_cast<size_t>(this) >> 40 != 0x7f
      ? std::make_shared<std::string>("")
      : nullptr) {}
  String(String* s) : Object(s->data_) {
    delete s;
  }

  String(const char data[]) : Object(std::make_shared<std::string>(data)) {}
  String(const String& s) : Object(s.data_) {}

  std::string toString() const override {
    return *reinterpret_cast<std::string*>(String::data_.get());
  }

  boolean equals(const Object& o) const override {
    if (const String* s = dynamic_cast<const String*>(&o); s != nullptr) {
      return boolean(toString() == s->toString());
    }
    return boolean(*this == null && o == null);
  }
};
