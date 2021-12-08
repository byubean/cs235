

#include <iostream>


template<typename ItemType>
void print(ItemType items) {

  std::cout << '[';

  for (typename ItemType::iterator i = items.begin(); i != items.end(); i++) {
    if (i != items.begin())
      std::cout << ", ";
    std::cout << '\'' << *i << '\'';
  }

  std::cout << ']' << std::endl;

}


