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
    ss << Vehicle::toString();
    ss << "Width: " << this->width << std::endl;
    ss << "Length: " << this->length << std::endl;

    return ss.str();
}

Boat& Boat::operator=(const Boat& orig) {
    this->width = orig.width;
    this->length = orig.length;

    return *this;
}

ostream& operator<<(ostream& os, const Boat& b) {
     os << b.toString();
     return os;
}


Boat::~Boat() {
    /*std::cout << "Boat destructor" << endl;*/
}

