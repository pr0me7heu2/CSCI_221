// Brasher, Bryan R
// 19-JUL-19
// Project 08

// driver for testing of template-based class that implements a set of items

#include "Brasher_Bryan - TempClassSet.h"
#include "Brasher_Bryan - TempClassSet.cpp"
#include <iostream>
#include <limits>

using namespace std;
using namespace BRASHERTEMPCLASSSET;

void print_menu(); // prints menu to screen


int main() {

    cout << "Welcome to the driver for Project 08" << endl;
    cout << "Let's create a few different sets of different datatypes." << endl;

    set<int> intList;
    int intItem;
    set<double> doubleList;
    double doubleItem;
    set<char> charList;
    char charItem;
    int int_choice;


    while (true) {

        print_menu();

        cin >> int_choice;

        switch (int_choice) {
            case 1:
                cout << "Enter an integer to add to set." << endl;
                cin >> intItem;
                while (cin.fail()) {
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear(); // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
                    cin >> intItem;
                }

                intList.add(intItem);

                cout << "Integer set is now:" << endl;
                cout << intList;
                break;

            case 2:
                cout << "Enter an integer to remove." << endl;
                cin >> intItem;
                while (cin.fail()) {
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear(); // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
                    cin >> intItem;
                }

                intList.remove(intItem);

                cout << "Integer set is now:" << endl;
                cout << intList;
                break;
            case 3:
                cout << "Enter an double to add to set." << endl;
                cin >> doubleItem;
                while (cin.fail()) {
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear(); // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
                    cin >> doubleItem;
                }

                doubleList.add(static_cast<double>(doubleItem));

                cout << "Double set is now:" << endl;
                cout << doubleList;
                break;

            case 4:
                cout << "Enter an double to remove." << endl;
                cin >> doubleItem;
                while (cin.fail()) {
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear(); // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
                    cin >> doubleItem;
                }

                doubleList.remove(doubleItem);

                cout << "Double set is now:" << endl;
                cout << doubleList;
                break;
            case 5:
                cout << "Enter an char to add to set." << endl;
                cin >> charItem;
                while (cin.fail()) {
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear(); // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
                    cin >> charItem;
                }

                charList.add(charItem);

                cout << "Char set is now:" << endl;
                cout << charList;
                break;

            case 6:
                cout << "Enter an char to remove." << endl;
                cin >> charItem;
                while (cin.fail()) {
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear(); // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
                    cin >> charItem;
                }

                charList.remove(charItem);

                cout << "Char set is now:" << endl;
                cout << charList;
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid entry." << endl;
        }
    }
}

void print_menu() {
    cout << "1. Add an integer." << endl;
    cout << "2. Remove an integer." << endl;
    cout << "3. Add a double." << endl;
    cout << "4. Remove a double." << endl;
    cout << "5. Add a char." << endl;
    cout << "6. Remove a char." << endl;
    cout << "7. Exit." << endl;
}
