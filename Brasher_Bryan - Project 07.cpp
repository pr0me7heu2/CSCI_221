// Brasher, Bryan, R
// Project 07
// 13-JUL-2019

/* Thank you again for allowing me to complete my assignments while I was
 * away on official travel.  I literally wrote this sitting on a jump seat
 * in the back of a C-130.  This is the first time that I have seen member
 * variables that could not be explicitly set (here you have to use other
 * functions to do so. */

#include <string>
#include <iostream>
#include <limits>

using namespace std;

class TimeFormatMistake { //exception class specific to errors of time format
public:
    TimeFormatMistake(); // default constructor
    TimeFormatMistake(string catchErrorMsg); // applies string to message value
    string get_message(); // returns message value
private:
    string message;  //holds message explaining error type
};

class Time {
public:
    Time(); // default constructor
    Time(int hr, int min) throw(TimeFormatMistake);
    // sets hour and minute respectively and assumes that format is 24-hr e.g. is12HR = 0
    // invalid values for hr and min throw an exception
    Time(int hr, int min, bool format, bool pm) throw(TimeFormatMistake);
    // sets hour and minute respectively; 12hr (format = 1), 24hr (format = 0)
    // afternoon is pm is 1, before noon if pm is 0
    // invalid values for hr and min throw an exception
    int getHour() const;
    // returns hour value
    int getMinute() const;
    // returns minute value
    bool getFormat() const;
    // returns time format value
    void setHour(int newHour) throw(TimeFormatMistake);
    // sets hour value
    // throws exception for invalid newHour
    // in order to set an hour valid for other format, must first use convertTime()
    void setMinute(int newMin) throw(TimeFormatMistake);
    // sets minute value
    // throws exception for invalid newMin
    void printTime();
    // returns time in HH:HH or hh:hh AM/PM format to cout
    void convertTime();
    // converts time object to opposite format
private:
    void isValid(int hr, int min, bool format) throw(TimeFormatMistake);
    // used in constructors to throw an exception if invalid hr or min values
    // are used for initialization
    int minute;
    int hour;
    bool is12HR;  // can only be changed implicitly via convertTime
    bool PM;  // can only be changed implicitly via convertTime or setHour
};


Time getTime() throw(TimeFormatMistake);
// returns time object using user input


int main() {
    char choice('y');
    Time userTime;

    try {

        cout << "Convert 24HR to 12HR time." << endl;

        while (choice == 'y' || choice == 'Y') {

            userTime = getTime();
            userTime.convertTime();
            userTime.printTime();


            cout << "\nAgain? (y/n)" << endl;
            cin >> choice;
        }
    }
    catch(TimeFormatMistake x) {
        cout << "Program stopped because of an " << x.get_message() << endl;
    }
    return 0;
}


Time getTime() throw(TimeFormatMistake){
    int h,m;
    char col; // for colon separating HH:MM

    cout << "Enter a time in 24-hour notation:" << endl;

    cin >> h >> col >> m;

    while (cin.fail()) {
        cout << "Invalid entry. Try again." << endl;
        cin.clear(); // clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear stream
        cin >> h >> col >> m;}

    return Time(h,m);
}

Time::Time() : hour(0), minute(0), is12HR(0), PM(NULL) {
}

Time::Time(int hr, int min) throw(TimeFormatMistake) {
    isValid(hr, min, 0);

    hour = hr;
    minute = min;
    is12HR = false;
    PM = NULL;  // AM/PM distinction not relevant when is12HR == false
    }


Time::Time(int hr, int min, bool format, bool pm) throw(TimeFormatMistake) {
    isValid(hr, min, format);

    hour = hr;
    minute = min;
    is12HR = format;
    PM = pm;
}

void Time::isValid(int hr, int min, bool format) throw(TimeFormatMistake) {
    if (min < 0 || min > 60)  // applies to all possibilities
        throw TimeFormatMistake("invalid minute value.");

    if (format == 0 && (hr > 24 || hr < 0))
        throw TimeFormatMistake("invalid hour value.");

    if (format == 1 && (hr > 12 || hr < 0))
        throw TimeFormatMistake("invalid hour value.");
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

bool Time::getFormat() const {
    return is12HR;
}

void Time::setHour(int newHour) throw(TimeFormatMistake){
    isValid(newHour, minute, is12HR);
    hour = newHour;
    if (is12HR && newHour >= 12)  // for changing values while is12HR == true
        PM = true;
    if (is12HR && newHour < 12)
        PM = false;
}

void Time::setMinute(int newMin) throw(TimeFormatMistake) {
    isValid(hour, newMin);  //does not matter what is value of is12HR
    minute = newMin;
}

void Time::printTime() {
    if (is12HR  && !PM)
        cout << hour << ":" << minute << " AM";
    if (is12HR  && PM)
        cout << hour << ":" << minute << " PM";
    if (!is12HR)
        cout << hour << ":" << minute;
}

void Time::convertTime() {
    if (is12HR) {  // conversion to 24HR; currently unused
        hour = hour + 12;
        is12HR = false;
        PM = NULL;
    }
    if (!is12HR && hour > 12) {
        hour = hour - 12;
        is12HR = true;
        PM = true;
    }
    if (!is12HR && hour == 12) {
        is12HR = true;
        PM = true;
    }
    if (!is12HR && hour < 12) {
        is12HR = true;
        PM = false;
    }
}

TimeFormatMistake::TimeFormatMistake() : message("") {
}

TimeFormatMistake::TimeFormatMistake(string catchErrorMsg) : message(catchErrorMsg) {
}

string TimeFormatMistake::get_message() {
    return message;
}


