#include "sailboat.h"
#include "vehicle.h"
#include "boat.h"
#include <sstream>
#include "string"

using namespace std;

SailBoat::SailBoat(string make, string model, int yearMade, int nrOfPassgengers, int width, int length, int sailArea)
    : Boat(make, model, yearMade, nrOfPassgengers, width, length) {

    this->sailArea = sailArea;
}

SailBoat::~SailBoat()
{

}

bool SailBoat::operator==(const SailBoat& right) {
    return (this->getMake() == right.getMake() && this->getModel() == right.getModel());
}

ostream& operator<<(ostream& os, const SailBoat& b) {
     os << b.toString();
     return os;
}

int SailBoat::getSailArea() const {
    return this->sailArea;
}

string SailBoat::getType() const {
    return "sailboat";
}

string SailBoat::toString() const {
    stringstream ss;
    ss << Boat::toString();
    ss << this->sailArea;
    return ss.str();
}

