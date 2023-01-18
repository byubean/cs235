//
// Created by Gordon Bean on 1/17/23.
//

#include "Book.h"

string Book::getTitle() const {
    return this->title;
}

string Book::getAuthor() const {
    return this->author;
}

int Book::getYear() const {
    return this->year;
}

string Book::str() const {
    stringstream ss;
    ss << this->title << " " << this->author << " " << this->year;
    return ss.str();
}
