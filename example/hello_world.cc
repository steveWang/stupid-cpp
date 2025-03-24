#include "read_only_string.h"

#include <iostream>

int main() {
  stupid::ReadOnlyString str = "hello world";
  std::cout << *&str << std::endl;
}
