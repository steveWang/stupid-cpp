module;

#include <iostream>
#include <string>

import sumatra;

export module System.out.println;

class _system {
 private:
  class Out {
   public:
    void println(const Object& s) {
      std::cout << s.toString() << "\n";
    }
  };
 public:
  Out out;
};

export _system System;
