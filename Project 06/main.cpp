// Brasher, Bryan R
// 13-JUL-2019
// Project 5

// application file

/* Thank you again for allowing me to complete this assignment while also
 * working overseas on official travel.  I commented out the driver program - as
 * supplied in the text because I wanted to include the ability to rename the objects. */

#include <iostream>
#include <string>
#include <limits>
#include "shape.h"

using namespace std;
using namespace BRASHERSHAPE;

int main() {
    // provided driver
//    Circle c(2);
//
//    cout << c.getName() << " has radius " << c.getRadius()
//    << " and area " << c.getArea() << "." << endl;

    // user created driver

    char choice, shape;
    string name;
    double r, h, w;

    do {

        cout << "Would you like to make a circle or a rectangle? (c/r)" << endl;

        cin >> shape;

        switch(shape) {
            case 'c':
            case 'C': {
                cout << "Choose a name for your circle:" << endl;

                cin.ignore();  //clear \n from stream
                getline(cin, name);

                cout << "Enter a radius:" << endl;
                cin >> r;
                while (cin.fail()) {
                    cout << "Invalid entry. Try again." << endl;
                    cin.clear(); //clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear stream
                    cin >> r;
                }

                Circle userCircle(name, r);

                cout << "Your circle named " << userCircle.getName() << " has radius " << userCircle.getRadius()
                << " and area " << userCircle.getArea() << "." << endl;
                break;
            }

            case 'r':
            case 'R': {
                cout << "Choose a name for your rectangle:" << endl;

                cin.ignore(); // clear \n from stream
                getline(cin, name);

                cout << "Enter height and width" << endl;

                cin >> h >> w;

                while (cin.fail()) {
                    cout << "Invalid entry.  Try again." << endl;
                    cin.clear();  // clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');  // clear stream
                    cin >> h >> w;
                }

                Rectangle userRect(name, h, w);

                cout << "Your rectangle name " << userRect.getName() << " has height " <<
                userRect.getHeight() << " and width " << userRect.getWidth() << " and area " <<
                userRect.getArea() << "." << endl;

                break;
            }

            default: {
                cout << "You did not enter a correct choice." << endl;
            }
        }

        cout << "Would you like to do it again? (y/n)" << endl;

        cin >> choice;

        while (choice !='y' && choice != 'Y' && choice != 'n' && choice != 'N'){
            cout << "Invalid entry." << endl;
            cout << "Would you like to do it again? (y/n)" << endl;
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
