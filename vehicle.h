#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using std::string;
class Vehicle {
public:
    Vehicle();
    Vehicle(string make, string model, int yearMade, int nrOfPassgengers);
    virtual ~Vehicle();

    void setMake(string make);
    string getMake() const;
    void setModel(string model);
    string getModel() const;
    void setYearMade(int yearMade);
    int getYearMade() const;
    void setNrOfPassengers(int nrOfPassengers);
    int getNrOfPassengers() const;

    virtual string toString() = 0;

private:
    string make;
    string model;
    int yearMade;
    int nrOfPassengers;

};

#endif // VEHICLE_H
