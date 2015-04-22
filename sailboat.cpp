#include "sailboat.h"
#include "vehicle.h"
#include "boat.h"
#include <sstream>

using namespace std;

SailBoat::SailBoat(string make, string model, int yearMade, int nrOfPassgengers, int width, int length, int someThingAboutTheSailsBoat)
    : Boat(make, model, yearMade, nrOfPassgengers, width, length) {

    this->someThingAboutTheSailsBoat = someThingAboutTheSailsBoat;
}

SailBoat::~SailBoat()
{

}

string SailBoat::toString() const {
    stringstream ss;
    ss << Boat::toString();
    ss << "someThingAboutTheSailBoat" << this->someThingAboutTheSailsBoat;
    return ss.str();
}

