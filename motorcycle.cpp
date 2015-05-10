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


bool Motorcycle::operator==(const Motorcycle& right) {
    return (this->getMake() == right.getMake() && this->getModel() == right.getModel());
}

string Motorcycle::toString() const {
    stringstream ss;
    ss << typeid(*this).name() << endl;
    ss << Vehicle::toString();
    ss << this->horsePower << endl;
    ss << this->cylinderVolume << endl;

    return ss.str();
}

int Motorcycle::getHorsePower() const {
    return this->horsePower;
}
int Motorcycle::getCylindervolume() const {
    return this->cylinderVolume;
}

string Motorcycle::getType() const {
    return "motorcycle";
}

/*ostream& operator<<(ostream& os, const Motorcycle& b) {
     os << b.toString();
     return os;
}*/


Motorcycle::~Motorcycle() {

}

