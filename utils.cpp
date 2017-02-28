#include "utils.h"

#include <iostream>
#include <cstdlib>

int ask_index(const char* allowed_ans) {
     while (true) {
          int a = std::tolower(std::cin.get());
          if (a == std::char_traits<char>::eof() || a == 'q') {
                std::cout << "quit!" << std::endl;
                std::exit(0);
          }
          for (int i = 0; allowed_ans[i] != 0; ++i)
              if (allowed_ans[i] == a) return i;
     }
}

