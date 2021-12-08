

#include <iostream>
#include <string>
#include <vector>


void print(std::vector<std::string> items) {

  std::cout << '[';

  for (unsigned i = 0; i < items.size(); i++) {
    if (i > 0)
      std::cout << ", ";
    std::cout << '\'' << items.at(i) << '\'';
  }

  std::cout << ']' << std::endl;

}


