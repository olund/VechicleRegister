#include "boat.h"
#include <iostream>
#include <sstream>

using std::stringstream;
using std::endl;

Boat::Boat(string make, string model, int yearMade, int nrOfPassgengers, int width, int length)
    : Vehicle(make, model, yearMade, nrOfPassgengers) {
    this->width = width;
    this->length = length;
}

Boat::Boat(const Boat &orig) {
    this->width = orig.width;
    this->length = orig.length;
}


string Boat::toString() const {
    stringstream ss;
    ss << typeid(*this).name() << endl;
    ss << Vehicle::toString();
    ss << this->width <<endl;
    ss << this->length << endl;

    return ss.str();
}

Boat& Boat::operator=(const Boat& orig) {
    this->width = orig.width;
    this->length = orig.length;

    return *this;
}

int Boat::getWidth() const {
    return this->width;
}

int Boat::getLength() const {
    return this->length;
}

ostream& operator<<(ostream& os, const Boat& b) {
     os << b.toString();
     return os;
}

string Boat::getType() const {
    return "boat";
}


Boat::~Boat() {
    /*std::cout << "Boat destructor" << endl;*/
}
