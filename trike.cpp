#include "trike.h"

Trike::Trike(string make, string model, int yearMade, int nrOfPassgengers, int horsePower, int cylinderVolume, int something)
    : Motorcycle(make, model, yearMade, nrOfPassgengers, horsePower, cylinderVolume)
{
    this->something = something;
}

string Trike::toString() const {

    stringstream ss;
    ss << Motorcycle::toString();
    ss << this->something << endl;

    return ss.str();
}

int Trike::getSomething() const {
    return this->something;
}

string Trike::getType() const {
    return "trike";
}


Trike::~Trike()
{

}

