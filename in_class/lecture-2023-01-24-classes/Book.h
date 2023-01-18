#ifndef IN_CLASS_BOOK_H
#define IN_CLASS_BOOK_H

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

class Book {
private:
    string title;
    string author;
    int year;
public:
    Book(string title, string author, int year) :
        title(title), author(author), year(year) {}

    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    string str() const;
};


#endif //IN_CLASS_BOOK_H
