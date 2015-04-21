#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(string make, string model, int yearMade, int nrOfPassgengers, int horsePower, int cylineVolume);
    ~Motorcycle();

    string toString();

private:
    int horsePower;
    int cylinderVolume;
};

#endif // MOTORCYCLE_H
