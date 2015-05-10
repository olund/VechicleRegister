#ifndef TRIKE_H
#define TRIKE_H
#include "motorcycle.h"
#include <sstream>

using namespace std;

class Trike : public Motorcycle
{
public:
    Trike(string make, string model, int yearMade, int nrOfPassgengers, int horsePower, int cylinderVolume, int something);
    ~Trike();
    string toString() const;
    virtual string getType() const;

    int getSomething() const;
private:
    int something;
};

#endif // TRIKE_H
