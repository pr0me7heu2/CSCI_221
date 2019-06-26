// Brasher, Bryan R
// 25-JUN-2019
// Project 4
// application file

/* This driver provides minimal infrastructure necessary to test
 * the interface and implementation files. */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <limits>
#include "Brasher_Bryan - Money.h"

int main()
{
    using namespace std;
    using namespace moneybrb;

    cout << "Welcome to the Money Driver." << endl;

    Money amount1, amount2;
    int percent;

    cout << "Enter in an amount of currency of the form $123.45." << endl;

    cin >> amount1;

    cout << "You entered " << amount1 << "." << endl;

    cout << '\n';

    cout << "Enter in a percent (enter 10 to indicate 10%)." << endl;

    cin >> percent;

    while(cin.fail())
    {
        cout << "Invalid entry." << endl;
        cout << "Try again." << endl;
        cin.clear(); // clear flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // skips to next newline
        cin >> percent;
    }

    amount2 = amount1.percent(percent);

    cout << percent  << "% of " << amount1 << " is " << amount2 << endl;

    cout << '\n';

    cout << "first amount < second amount: " << (amount1 < amount2) << endl;
    cout << "first amount > second amount: " << (amount1 > amount2) << endl;

    return 0;

}


