#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using std::string;
class Vehicle {
public:
    Vehicle();
    Vehicle(string make, string model, int yearMade, int nrOfPassgengers);

    void setMake(string make);
    string getMake();
    void setModel(string model);
    string getModel();
    void setYearMade(int yearMade);
    int getYearMade();
    void setNrOfPassengers(int nrOfPassengers);
    int getNrOfPassengers();



    ~Vehicle();
private:
    string make;
    string model;
    int yearMade;
    int nrOfPassengers;

};

#endif // VEHICLE_H
