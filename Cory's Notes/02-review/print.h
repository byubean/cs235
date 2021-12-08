

#include <iostream>
#include <vector>

#include "Book.h"


void print(const std::vector<Book>& list) {

  std::cout << std::endl;

  for (auto& book : list)
    std::cout << book.toString() << std::endl;

  std::cout << std::endl;

}


