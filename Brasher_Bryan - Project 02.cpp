// Brasher, Bryan R
// 13-JUN-2019
// Project 2
// Version 1.1

/* This program tests a new implementation of the CDAccount framework provided.
 *
 * Version 1.0 intended on presenting the user with a menu and then using a switch
 * statement, do-while loop, and a "counter" to force the user to - when they were
 * ready - to go through each test one, by one.  It was only after writing this code
 * I received a 'jump to case label error' which I found to be due to initializing
 * variables in some cases and then using them in others which is protects the integrity
 * in case user does not actually go in the order that I envisioned.
 *
 * I then sought to break up the code a bit.  Being a linux user, I always found system()
 * not a good way to go for waiting for user input. (needs to be OS specific).  I found this
 * neat article https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?id=1043284385&answer=1042856625
 * that outlines an OS-independent method that I briefly use here.
 *
 * If I were to follow this up with another version, I would institute stricter
 * user validation.*/


#include <iostream>
#include <cmath>
#include <limits>
#include <ios>

using namespace std;

class CDAccount
{
public:
    CDAccount();
    CDAccount(double new_balance, double new_interest_rate, int new_term);
    double get_initial_balance() const;
    double get_balance_at_maturity() const;
    double get_interest_rate() const;
    int get_term() const;
    void input(istream& in);
    void output(ostream& out);

private:
    int dollar;
    int cent;
    double interest_rate;  //fraction
    int term; // months until maturity
};

void intro();
// prints the instructions and plan

CDAccount test_3();
//pulls user input and then uses the 3-parameter-constructor


void mypause();
// halts progression until user gives keyboard input

int main()
{
    intro();

    mypause();

    cout.precision(2);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);

    // test default constructor
    cout << "***1***" << endl;
    CDAccount account1;
    cout << "account1 declared and initialized." << endl;
    cout << "\n";

    // Test CDAccount::input()
    cout << "***2***" << endl;

    cout << "Provide balance, rate, and term information." << endl;
    cout << "Place a space between each and do not include a $." << endl;
    cout << "Example:  1234.56 0.02 12" << endl;
    cout << "Describes a CD with a $1234.56 at 2% APR with a 12 month term." << endl;

    account1.input(cin);

    cout << "account1 has been updated." << endl;

    cout << "\n";

    // Test three-parameter-constructor
    cout << "***3***" << endl;

    CDAccount account2 = test_3();
    cout <<"account2 declared and initialized." << endl;
    cout << "\n";

    // Test CDAccount::get_initial_balance()
    cout << "***4***" << endl;

    cout << "Balance for account1 is $" << account1.get_initial_balance() << "." << endl;
    cout << "Balance for account2 is $" << account2.get_initial_balance() << "." << endl;
    cout << "\n";

    // Test CDAccount::get_balance_at_maturity()
    cout << "***5***" << endl;

    cout << "Balance at maturity for account1 is $" << account1.get_balance_at_maturity() << "." << endl;
    cout << "Balance at maturity for account2 is $" << account2.get_balance_at_maturity() << "." << endl;
    cout << "\n";

    // Test CDAccount::get_interest_rate()
    cout << "***6***" << endl;

    cout << "APR for account1: " << 100*account1.get_interest_rate() << "%." << endl;
    cout << "APR for account2: " << 100*account2.get_interest_rate() << "%." << endl;
    cout << "\n";

    // Test CDAccount::get_term()
    cout << "***7***" << endl;

    cout << "account1 has a term of " << account1.get_term() << " months." << endl;
    cout << "account2 has a term of " << account2.get_term() << " months." << endl;
    cout << "\n";

    // Test CDAccount::output()
    cout << "***8***" << endl;

    cout << "account1" << endl;
    account1.output(cout);
    cout << "account2" << endl;
    account2.output(cout);
    cout << "\n";

    char choice;
    do {
        cout << "Would you like to do that again? (y/n)" << endl;
        cin >> choice;
    }while(choice != 'y' && choice != 'Y' &&  choice != 'n' && choice != 'N');

    if (choice == 'y' || choice == 'Y')
        main();

    return 0;

}

void intro()
{

    cout << "\n\t******************Project 2************************";
    cout << "\n\t*                Instructions                     *";
    cout << "\n\t* Go through each step one at a time.             *";
    cout << "\n\t*                                                 *";
    cout << "\n\t* Doing this will create two different objects.   *";
    cout << "\n\t*                                                 *";
    cout << "\n\t* You can restart/quit at anytime from the menu.  *";
    cout << "\n\t*                                              brb*";
    cout << "\n\t***************************************************";
    cout << "\n";
    cout << "\n\t******************Project 2************************";
    cout << "\n\t*                   Plan                          *";
    cout << "\n\t* 1. Test default constructor                     *";
    cout << "\n\t* 2. Test CDAccount::input()                      *";
    cout << "\n\t* 3. Test three-parameter-constructor             *";
    cout << "\n\t* 4. Test CDAccount::get_initial_balance()        *";
    cout << "\n\t* 5. Test CDAccount::get_balance_at_maturity()    *";
    cout << "\n\t* 6. Test CDAccount::get_interest_rate()          *";
    cout << "\n\t* 7. Test CDAccount::get_term()                   *";
    cout << "\n\t* 8. Test CDAccount::output()                     *";
    cout << "\n\t* 9. Start Over / Quit                            *";
    cout << "\n\t***************************************************";
    cout << "\n";
    cout << "Are you ready?" << endl;
}

CDAccount test_3()
{
    double bal, rate; //temp variables for user input
    int term;

    cout << "Provide balance, rate, and term information." << endl;
    cout << "Place a space between each and do not include a $." << endl;
    cout << "Example:  1234.56 0.02 12" << endl;
    cout << "Describes a CD with a $1234.56 at 2% APR with a 12 month term." << endl;
    cout << "Note that the APR is in a fraction." << endl;

    cin >> bal >> rate >> term;

    while ((bal<0) || (rate<0) || (term<0))  //validation of user input
    {
        cout << "Invalid entries.  Try again." << endl;
        cout << "Example:  1234.56 0.02 12" << endl;
        cin >> bal >> rate >> term;
    }

    CDAccount account(bal,rate,term); //3-param constructor
    return (account);
}

CDAccount::CDAccount() : dollar(0),cent(0),interest_rate(0),term(0)
{
    //blank
}


CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    dollar = static_cast<int>(floor(new_balance));
    cent = static_cast<int>(floor((new_balance-dollar)*100));
    interest_rate = new_interest_rate;
    term = new_term;
}

double CDAccount::get_initial_balance() const
{
    return (dollar + 0.01 * cent);
}

double CDAccount::get_balance_at_maturity() const
{
    /* Calculation of balance at maturity uses the following:
     * A = P*(1 + r/n)^(nt), where
     * A - balance at maturity
     * P - principal
     * r - the APR as a decimal
     * n - number of times interest is compounded every year.
     *     (Google shows that is normally daily for CDs --> n=365)
     * t - time (in years) --> t = term / 12 */

    return ( get_initial_balance() * pow( (1 + interest_rate / 365),(365*static_cast<double>(term)/12) ));

}

double CDAccount::get_interest_rate() const
{
    return interest_rate;
}

int CDAccount::get_term() const
{
    return term;
}

void CDAccount::input(istream& in)  //function provided by instructor

{
    double balance;
    in >> balance; // get initial balance from user

    // convert balance to dollars and cents since this is how balance stored
    dollar = (int) balance; // dollar is the interger part of balace
    cent = (int) ((balance - dollar)*100); // cent is the fraction part * 100

    in >> interest_rate; // get interest rate from user
    in >> term; // get term from user
}

void CDAccount::output(ostream &out)
{
    out << "Balance: " << (dollar + 0.01 * cent) << " Interest Rate: " << interest_rate << " Term: "
    << term << " months." << endl;

}

void mypause()
{
    cout<<"Press [Enter] to continue . . .";
    cin.get();
}