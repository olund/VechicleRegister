#include "vehicle.h"
#include <string>

using std::string;


Vehicle::Vehicle() {
    this->make = "Unknown";
    this->model = "Unknown";
    this->yearMade = -1;
    this->nrOfPassengers = -1;
}

Vehicle::Vehicle(string make, string model, int yearMade, int nrOfPassgengers) {
    this->make = make;
    this->model = model;
    this->yearMade = yearMade;
    this->nrOfPassengers = nrOfPassgengers;
}

Vehicle::~Vehicle() {}


/* GETTERS AND SETTERS */
void Vehicle::setMake(string make) { this->make = make; }
string Vehicle::getMake() { return this->make; }
void Vehicle::setModel(string model) { this->model = model; }
string Vehicle::getModel() { return this->model; }
void Vehicle::setYearMade(int yearMade) { this->yearMade = yearMade; }
int Vehicle::getYearMade() { return this->yearMade; }
void Vehicle::setNrOfPassengers(int nrOfPassengers) { this->nrOfPassengers = nrOfPassengers; }
int Vehicle::getNrOfPassengers() { return this->nrOfPassengers; }







