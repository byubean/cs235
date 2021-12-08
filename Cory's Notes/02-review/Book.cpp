

#include <iostream>
#include <sstream>
#include <string>

#include "Book.h"

using std::string;
using std::stringstream;


void Book::setTitle(string title) {
  this->title = title;
}

void Book::setAuthor(string author) {
  this->author = author;
}

string Book::toString() const {
  stringstream out;
  out << "Book: title: " << title << " author: " << author;
  return out.str();
}


