#ifndef BOAT_H
#define BOAT_H
#include <iostream>
#include "vehicle.h"

using namespace std;

class Boat : public Vehicle {
public:
    Boat(string make, string model, int yearMade, int nrOfPassgengers, int width, int length);
    ~Boat();

    Boat(const Boat &orig);


    string toString() const;

    Boat& operator=(const Boat& orig);
    virtual string getType() const;

    int getWidth() const;
    int getLength() const;

    friend ostream& operator<<(ostream& os, const Boat& b);
private:
    int width;
    int length;
};

#endif // BOAT_H
