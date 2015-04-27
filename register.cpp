#include "register.h"

Register::Register()
{
    this->vehicles = new MyVector<Vehicle>();
    this->fileHandler = new FileHandler<Vehicle>();
}

Register::~Register() {
    delete vehicles;
    delete fileHandler;
}

