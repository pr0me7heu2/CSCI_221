// Brasher, Bryan R
// 13-JUL-2019
// Project 05

// implementation file

#include <string>
#include "shape.h"

using namespace std;

namespace BRASHERSHAPE
{
// shape implementation (with data type changes)

Shape::Shape() {
    name = "";
}

Shape::Shape(string name) {
    this->name = name;
}

string Shape::getName() {
    return this->name;
}

void Shape::setName(string newName) {
    this->name = newName;
}

// circle implementation

Circle::Circle() : Shape("Circle"), radius(0)
{ }

Circle::Circle(double theRadius) : Shape("Circle"), radius(theRadius)  //uses Shape construct. to set name
{ }

Circle::Circle(string theName, double theRadius){
    this->setName(theName); //private variables of base class not directly available to derived class
    radius = theRadius;
}

void Circle::setRadius(double newRadius) {
    radius = newRadius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getArea() {
    return (3.14159 * radius * radius);
}

// rectangle implementation

Rectangle::Rectangle() : Shape("Rectangle"), height(0), width(0)
{ }

Rectangle::Rectangle(double theHeight, double theWidth) : Shape("Rectangle"), height(theHeight), width(theWidth)
{ }

Rectangle::Rectangle(string theName, double theHeight, double theWidth){
    this->setName(theName);  // accesses private variable name by using this to call shape class member function
    height = theHeight;
    width = theWidth;
}

void Rectangle::setWidth(double newWidth) {
    width = newWidth;
}

void Rectangle::setHeight(double newHeight) {
    height = newHeight;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getArea() {
    return (height * width);
}

}
