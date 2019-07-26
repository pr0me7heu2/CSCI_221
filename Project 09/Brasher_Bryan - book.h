// Brasher, Bryan
// Project 09
// 25 July 2019

// interface file

#ifndef BOOK_H

#define BOOK_H

#include <string>
using namespace std;

namespace BRASHERBOOKS {

    class Book {
    public:
        Book(); // default constructor
        Book(string newAuthor, string newTitle, string newYear); // fully constructor
        void setAuthor(string newAuthor); // mutators
        void setTitle(string newTitle);
        void setYear(string newYear);
        string getAuthor() const; // accessors
        string getTitle() const;
        string getYear() const;
        friend bool operator <(const Book& book1, const Book& book2);
        // needed for sorting by author using lexicographical comparison
        friend ostream& operator <<(ostream& outs, const Book& book);
        // outputs author, title, and year in easily human readable format
    private:
        string author, title, year;
    };
}

#endif