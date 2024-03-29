// Brasher, Bryan
// Project 09
// 25-JUL-2019

// application file

#include "Brasher_Bryan - book.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
using namespace BRASHERBOOKS;

void addBook(vector<Book> &lib);

void removeBook(vector<Book> &lib);

void sortLibrary(vector<Book> &lib);

void printLibrary(vector<Book> &lib);

void loadLibrary(vector<Book>& lib);

void saveLibrary(vector<Book>& lib);

void printMenu();

int main() {

    vector<Book> library;
    int choice;

    while(true) {
        printMenu();

        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                removeBook(library);
                break;
            case 3:
                printLibrary(library);
                break;
            case 4:
                cout << "Not yet implemented." << endl;
                break;
            case 5:
                saveLibrary(library);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid entry.  Try again." << endl;
        }
    }
}

void addBook(vector<Book> &lib) {
    string author, title, year;

    cout << "Enter author name (Last name, First Name):" << endl;
    cin.ignore();  //clear \n from stream
    getline(cin, author);

    cout << "Enter title of the book:" << endl;
    getline(cin, title);

    cout << "Enter year of publication:" << endl;
    getline(cin, year);

    Book newBook(author,title,year); //created newBook object using constructor

    lib.push_back(newBook); //newBook added to vector container
}

void removeBook(vector<Book> &lib) {
    if (lib.empty()) {
        cout << "Library is empty." << endl;
    }
    else {
        string author, title, year;

        cout << "Enter author name (Last name, First Name):" << endl;
        cin.ignore();  //clear \n from stream
        getline(cin, author);

        cout << "Enter title of the book to remove:" << endl;
        getline(cin, title);

        cout << "Enter year of publication:" << endl;
        getline(cin, year);

        Book targetBook(author,title,year);

        vector<Book>::iterator it; //creates iterator
        it = find(lib.begin(), lib.end(), targetBook);  //uses generic find function

        if(it != lib.end()) {  //find returns .end() if not found
            lib.erase(it); //erases book pointed to by it
            cout << targetBook;
            cout << "was removed from the library." << endl;
        }

        else {
            cout << "That book was not found.  Check your input and try again." << endl;
        }

    }
}
void printLibrary(vector<Book> &lib) {
    sortLibrary(lib); //sorts list by author
    \
    cout << "Library currently contains:" << endl;

    for (const auto & i : lib) {
        cout << i;
    }
}

void sortLibrary(vector<Book> &lib) {
    sort(lib.begin(), lib.end());  // using generic sort function
}

void loadLibrary(vector<Book>& lib) {
    // likely requires some kind of marking in the print fields
    // to then recreate objects from each line of the saved file
}

void saveLibrary(vector<Book>& lib) {
    string fileName;
    cout << "Enter name of library: " << endl;
    cin >> fileName;
    ofstream outputFile;
    outputFile.open(fileName);

    sortLibrary(lib);

    for (const auto & i : lib) {
        outputFile << i;  // copies library to file
    }

    outputFile.close();

    cout << "Library saved!" << endl;
}


void printMenu() {
    cout << "********LIBRARY***********" << endl;
    cout << "** 1. Add a book        **" << endl;
    cout << "** 2. Remove a book     **" << endl;
    cout << "** 3. Show contents     **" << endl;
    cout << "** 4. Load library      **" << endl;
    cout << "** 5. Save library      **" << endl;
    cout << "** 6. Quit              **" << endl;
    cout << "**************************" << endl;
}