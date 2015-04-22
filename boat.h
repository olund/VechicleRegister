#ifndef BOAT_H
#define BOAT_H
#include <iostream>
#include "vehicle.h"

using namespace std;

class Boat : public Vehicle
{
public:
    Boat(string make, string model, int yearMade, int nrOfPassgengers, int width, int length);
    ~Boat();


    string toString() const;

    friend ostream& operator<<(ostream& os, const Boat& b);
private:
    int width;
    int length;
};

#endif // BOAT_H
