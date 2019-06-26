// Brasher, Bryan R
// 25-JUN-2019
// Project 4
// implementation file

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "Brasher_Bryan - Money.h"

using namespace std;

// helper function definition

int digit_to_int(char c){
    return (static_cast<int>(c) - static_cast<int>('0'));
}

//used in the definition of the overloaded input operator >>
//Pre: c is one of the digits '0' - '9'
//Post: Returns the integer for the digit e.g. '3' --> 3



namespace moneybrb {

    //friend function definitions

    Money operator +(const Money& amount1, const Money& amount2) {
        Money temp;
        temp.all_cents = amount1.all_cents + amount2.all_cents;
        return temp;
    }

    Money operator -(const Money& amount1, const Money& amount2) {
        Money temp;
        temp.all_cents = amount1.all_cents - amount2.all_cents;
        return temp;
    }

    Money operator -(const Money& amount) {
        Money temp;
        temp.all_cents = -amount.all_cents;
        return temp;
    }

    bool operator ==(const Money& amount1, const Money& amount2) {
        return (amount1.all_cents == amount2.all_cents);
    }

    bool operator <(const Money& amount1, const Money& amount2) {
        return (amount1.all_cents < amount2.all_cents);
    }

    bool operator >(const Money& amount1, const Money& amount2) {
        return (amount1.all_cents > amount2.all_cents);
    }

    bool operator <=(const Money& amount1, const Money& amount2) {
        return ((amount1.all_cents < amount2.all_cents) || (amount1.all_cents == amount2.all_cents));
    }

    bool operator >=(const Money& amount1, const Money& amount2) {
        return ((amount1.all_cents > amount2.all_cents) || (amount1.all_cents == amount2.all_cents));
    }


    istream& operator >>(istream& ins, Money& amount) {
        char one_char, decimal_point; // read (-), $ and decimal
        char digit1, digit2; // read amount of cents
        long dollars;
        int cents;
        bool negative; //sets to true if value is negative

        ins >> one_char;

        if (one_char == '-')
        {
            negative = true;
            ins >> one_char; // read $
        }

        else
            negative = false;

        // if input is legal, then one_char == '$'

        ins >> dollars >> decimal_point >> digit1 >> digit2;

        if (one_char !='$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
        {
            cout << "Error illegal form for money input." << endl;
            exit(1);
        }

        cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

        amount.all_cents = dollars * 100 + cents;

        return ins;
    }

    ostream& operator <<(ostream& outs, const Money& amount) {
        long positive_cents, dollars, cents;

        positive_cents = labs(amount.all_cents);
        dollars = positive_cents / 100;
        cents = positive_cents % 100;

        if (amount.all_cents < 0)
            outs << "- $" << dollars << '.';
        else
            outs << "$" << dollars << '.';

        if (cents < 10)  // ensures .00 output
            outs << "0";

        outs << cents;

        return outs;
    }

    // constructor definitions
    Money::Money(long dollars, int cents) {
        if (dollars * cents < 0) // if one is negative & one is positive
        {
            cout << "Illegal values for dollars and cents." << endl;
            exit(1);
        }
        all_cents = dollars * 100 + cents;
    }

    Money::Money(long dollars) : all_cents(dollars*100) {
        // body intentionally blank
    }

    Money::Money() : all_cents(0) {
        // body intentionally blank
    }

    // public member function definitions
    double Money::get_value() const {
        return (all_cents * 0.01);
    }

    Money Money::percent(int percent_figure) const {
        Money temp;
        temp.all_cents = all_cents*(percent_figure*.01);  //works for percentages > and < 100%
        return temp;
    }

}

