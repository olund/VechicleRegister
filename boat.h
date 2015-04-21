#ifndef BOAT_H
#define BOAT_H
#include "vehicle.h"

class Boat : public Vehicle
{
public:
    Boat(string make, string model, int yearMade, int nrOfPassgengers, int width, int length);
    ~Boat();

    string toString();

private:
    int width;
    int length;
};

#endif // BOAT_H
