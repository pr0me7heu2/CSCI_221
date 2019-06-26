// Brasher, Bryan R
// 25-JUN-2019
// Project 4
// interface file

/* Header file: this is the interface for the class Money.
 * Values of this type are for amounts of money is U.S. currency.*/

#ifndef MONEY_H

#define MONEY_H

#include <iostream>

using namespace std;

namespace moneybrb {

    class Money {
    public:
        // friend definitions
        friend Money operator +(const Money& amount1, const Money& amount2);

        friend Money operator -(const Money& amount1, const Money& amount2);

        friend Money operator -(const Money& amount);

        friend bool operator ==(const Money& amount1, const Money& amount2);

        friend bool operator <(const Money& amount1, const Money& amount2);

        friend bool operator >(const Money& amount1, const Money& amount2);

        friend bool operator <=(const Money& amount1, const Money& amount2);

        friend bool operator >=(const Money& amount1, const Money& amount2);

        friend istream& operator >>(istream& ins, Money& amount);

        friend ostream& operator <<(ostream& outs, const Money& amount);

        // constructors
        Money(long dollars, int cents);

        Money(long dollars);

        Money();

        // public member functions
        double get_value() const;
        // returns the total_cents value in Money object

        Money percent(int percent_figure) const;
        // returns a money object with total_cents value equivalent
        // to percent_figure  % of the value of the calling object

    private:
        long all_cents;

    };

}

#endif MONEY_H