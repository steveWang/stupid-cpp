module;

#include <memory>
#include <string>
#include <string_view>

export module String;

import Object;

export class String : public Object {
 public:
  String() : Object(
      reinterpret_cast<size_t>(this) >> 40 != 0x7f
      ? std::make_shared<std::string>("")
      : nullptr) {}

  String(const char data[]) : Object(std::make_shared<std::string>(data)) {}
  String(String* data) : Object(data->data_) {}
  String(const String& s) : Object(s.data_) {}

  std::string toString() const override {
    return *reinterpret_cast<std::string*>(String::data_.get());
  }
};
