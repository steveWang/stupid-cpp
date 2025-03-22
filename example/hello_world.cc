#include "read_only_string.h"

#include <iostream>
#include <string_view>

int main() {
  stupid::ReadOnlyString str = "hello world";

  std::cout << *(&str) << std::endl;
}
