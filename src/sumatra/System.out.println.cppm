module;

#include <iostream>
#include <string>

import base;
import sumatra;

export module System.out.println;

class _system {
 private:
  class Out {
   public:
    void println(const auto& s) const {
      std::cout << s.toString() << "\n";
    }
    void println(boolean b) const {
      println(Boolean(b));
    }
    void println(const char s[]) const {
      println(String(s));
    }
  };
 public:
  Out out;
};

export _system System;
