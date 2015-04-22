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


string Boat::toString() {
    stringstream ss;
    ss << "Width: " << this->width << std::endl;
    ss << "Length: " << this->length << std::endl;

    return ss.str();
}

ostream& operator<<(ostream& os, const Boat& b) {
     os << b.toString();
     return os;
}


Boat::~Boat() {
    std::cout << "Boat destructor" << endl;
}

