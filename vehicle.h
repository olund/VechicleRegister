#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using std::string;
class Vehicle {
public:
    Vehicle();
    Vehicle(string make, string model, int yearMade, int nrOfPassgengers);
    virtual ~Vehicle();

    // Copy ctor
    Vehicle(const Vehicle &orig);

    void setMake(string make);
    string getMake() const;
    void setModel(string model);
    string getModel() const;
    void setYearMade(int yearMade);
    int getYearMade() const;
    void setNrOfPassengers(int nrOfPassengers);
    int getNrOfPassengers() const;

    bool operator==(const Vehicle& right);
    Vehicle& operator=(const Vehicle& orig);

    virtual string toString() const = 0;
    virtual string getType() const;
private:
    string make;
    string model;
    int yearMade;
    int nrOfPassengers;

};

#endif // VEHICLE_H
