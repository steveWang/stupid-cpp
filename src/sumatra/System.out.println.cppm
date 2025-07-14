module;

#include <iostream>

import String;

export module System.out.println;

class _system {
 private:
  class Out {
   public:
    void println(const String& s) {
      std::cout << s.toString() << "\n";
    }
  };
 public:
  Out out;
};

export _system System;
