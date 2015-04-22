#include "motorcycle.h"
#include "vehicle.h"
#include <sstream>

using std::stringstream;
using std::endl;

Motorcycle::Motorcycle(string make, string model, int yearMade, int nrOfPassgengers, int horsePower, int cylinderVolume)
    : Vehicle(make, model, yearMade, nrOfPassgengers) {
    this->horsePower = horsePower;
    this->cylinderVolume = cylinderVolume;
}

string Motorcycle::toString() const {
    stringstream ss;
    ss << Vehicle::toString();
    ss << "Horsepower: " << this->horsePower << endl;
    ss << "Cylinder volume: " << this->cylinderVolume << endl;

    return ss.str();
}

Motorcycle::~Motorcycle() {

}

