module;

#include <memory>
#include <string>
#include <string_view>

export module String;

export class String {
 public:
  String() {
    if (reinterpret_cast<size_t>(this) >> 40 != 0x7f) {
      data_ = std::make_shared<std::string>("");
    }
  }

  String(const char data[]) : data_(std::make_shared<std::string>(data)) {}
  String(String* data) : data_(data->data_) {}
  String(const String& s) : data_(s.data_) {}

  const std::string_view toString() const {
    return *data_;
  }

  // This is just some trickery to make sure that we get an address on the
  // heap, not the stack.
  void* operator new(size_t count) {
    void* data = std::calloc(1, 1);
    std::free(data);
    return data;
  }

  // We'll probably want to create an Object class, make String subclass
  // Object, and move the definition of null to be a plain Object.
  bool operator==(const String& o) const {
    if (data_ == nullptr) {
      return o.data_ == nullptr;
    }
    if (o.data_ == nullptr) {
      return false;
    }
    return *data_ == *o.data_;
  }

  std::shared_ptr<std::string> data_;
};

export String null = (String*) nullptr;
