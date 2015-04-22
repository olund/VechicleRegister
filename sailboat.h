#ifndef SAILBOAT_H
#define SAILBOAT_H

#include <string>
#include "boat.h"

using namespace std;


class SailBoat : public Boat {
public:
    SailBoat(string make, string model, int yearMade, int nrOfPassgengers,
             int width, int length,
             int someThingAboutTheSailsBoat);
    ~SailBoat();

    string toString() const;

private:
    int someThingAboutTheSailsBoat;
};

#endif // SAILBOAT_H
