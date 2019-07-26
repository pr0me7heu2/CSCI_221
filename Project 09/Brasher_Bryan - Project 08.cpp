// Brasher, Bryan
// Project 09
// 25 July 2019

// implementation file

#include "Brasher_Bryan - book.h"
#include <string>
#include <iostream>

namespace BRASHERBOOKS {
    Book::Book() : author(""), title(""), year("") {
    }

    Book::Book(string newAuthor, string newTitle, string newYear)  :
    author(newAuthor), title(newTitle), year(newYear) {
    }

    void Book::setAuthor(string newAuthor)  {
        author = newAuthor;
    }

    void Book::setTitle(string newTitle) {
        title = newTitle;
    }

    void Book::setYear(string newYear) {
        year = newYear;
    }

    string Book::getAuthor() const { return author; }

    string Book::getTitle() const { return title; }

    string Book::getYear() const { return year; }

    bool operator <(const Book& book1, const Book& book2) {
        return (book1.author < book2.author);
    }

    ostream& operator <<(ostream& outs, const Book& book) { // outputs members separated by a space
        outs << book.author << " " << book.title << " " << book.year << endl;
        return outs;
    }

    bool operator ==(const Book& book1, const Book& book2) { // true if all members are equal
        return( book1.author == book2.author &&
        book1.title == book2.title &&
        book1.year == book2.year);
    }
}