#include "register.h"

Register::Register()
{
    this->vehicles = new MyVector<Vehicle>();
    this->fileHandler = new FileHandler<Vehicle>();
}


MyVector<Vehicle>& Register::getVehicles() const {
    return *this->vehicles;
}

/*MyVector<Vehicle>& Register::getVehicles() {
    return this->vehicles;
}*/

FileHandler<Vehicle>& Register::getFileHandler() const {
    return *this->fileHandler;
}

int Register::findVehicle(string el) const {
    int pos = -1;
    bool found = false;

    for (int i = 0; i < this->vehicles->getSize() && !found; i++) {
        if (this->vehicles->elementAt(i).getMake() + " - " + this->vehicles->elementAt(i).getModel() == el) {
            pos = i;
            found = true;
        }
    }

    return pos;
}

Register::~Register() {
    delete vehicles;
    delete fileHandler;
}

