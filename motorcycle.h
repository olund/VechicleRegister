#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include <iostream>
#include "vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(string make, string model, int yearMade, int nrOfPassgengers, int horsePower, int cylinderVolume);
    ~Motorcycle();

    string toString() const;

    bool operator==(const Motorcycle& right);
    virtual string getType() const;
    //friend ostream& operator<<(ostream& os, const Motorcycle& b);
    int getHorsePower() const;
    int getCylindervolume() const;

private:
    int horsePower;
    int cylinderVolume;
};

#endif // MOTORCYCLE_H
