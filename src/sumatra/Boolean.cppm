module;

#include <memory>
#include <string>

import base;
import Object;

export module Boolean;

export class Boolean : public Object {
 public:
  Boolean() : Object(nullptr) {}
  Boolean(Boolean* o) : Object(o->data_) {
    delete o;
  }

  Boolean(bool b) : Object(std::make_shared<boolean>(static_cast<boolean>(b))) {}
  Boolean(boolean b) : Object(std::make_shared<boolean>(b)) {}
  Boolean(const Boolean& o) : Object(o.data_) {}

  std::string toString() const override {
    if  (booleanValue()) {
      return "true";
    }
    return "false";
  }

  boolean booleanValue() const {
    return *reinterpret_cast<boolean*>(data_.get());
  }

  using enum boolean;
};
