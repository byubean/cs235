#include "Book.h"
#include <sstream>
#include <string>
using std::stringstream;
using std::string;


string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return this->author;
}

int Book::getYear() const {
    return this->year;
}

string Book::str() const {
    stringstream ss;
    ss << this->getTitle() << " " << this->getAuthor() << " written in " << this->getYear();
    return ss.str();
}
