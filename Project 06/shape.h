// Brasher, Bryan R
// 13-JUL-2019
// Project 05

// interface file

#ifndef PROJECT_06_SHAPE_H
#define PROJECT_06_SHAPE_H

#include <string>

using namespace std;

namespace BRASHERSHAPE

{
class Shape { // stores nondescript shape objects
public:
    Shape(); // default constructor
    Shape(string name); // marked explicit to avoid unintentional implicit conversions
    string getName();  // accessor function
    void setName(string newName); // mutator function
    virtual double getArea() = 0; //implementation determined at runtime
private:
    string name;
};

class Circle : public Shape { // stores circle objects
public:
    Circle();
    Circle(double theRadius);  //marked explicit to avoid unintentional implicit conversions
    // sets radius to theRadius, sets name to circle
    Circle(string theName, double theRadius); //added for better initialization options
    // sets radius to theRadius, sets name to theName
    void setRadius(double newRadius);
    // mutator for chaning radius value
    double getRadius() const;
    // accessor for returning radius value
    virtual double getArea();
    // returns calculated area value
private:
    double radius;  // changed to double (from textbook)
};

class Rectangle : public Shape { // stores rectangle objects
public:
    Rectangle();
    Rectangle(double theHeight, double theWidth);
    // sets height and width, sets name to rectangle
    Rectangle(string theName, double theHeight, double theWidth);
    // sets name, height, and width respectively
    void setHeight(double newHeight);
    // mutator for height value
    void setWidth(double newWidth);
    // mutator for width value
    double getHeight() const;
    // accessor for height value
    double getWidth() const;
    // accessor for width value
    virtual double getArea();
    // returns calculates area value
private:
    double height;
    double width;

};

}

#endif //PROJECT_06_SHAPE_H
