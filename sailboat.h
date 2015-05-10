#ifndef SAILBOAT_H
#define SAILBOAT_H

#include <string>
#include "boat.h"

using namespace std;


class SailBoat : public Boat {
public:
    SailBoat(string make, string model, int yearMade, int nrOfPassgengers,
             int width, int length,
             int sailArea);
    ~SailBoat();

    string toString() const;
    virtual string getType() const;

    bool operator==(const SailBoat& right);
    friend ostream& operator<<(ostream& os, const SailBoat& b);

    int getSailArea() const;

private:
    int sailArea;
};

#endif // SAILBOAT_H
