#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include "myvector.h"
#include <fstream>
#include <string>
#include "vehicle.h"
#include "boat.h"
#include "motorcycle.h"
#include "regex"

using namespace std;

template <typename T>
class FileHandler
{
public:

    FileHandler() {
        this->filename = "data.txt";
    }

    FileHandler(string filename) {
        this->filename = filename;
    }

    bool read(MyVector<T> *&vector) {
        ifstream read(this->filename);

        int size = 0;

        if (read.is_open()) {

            string make,
                model,
                type;

            int yearMade,
                nrOfPassengers,
                width,
                length;

            int hp;
            int cv;

            // Read size
            read >> size;

            Vehicle *v = nullptr;

            // Read until we have no elements left
            for (int i = 0; i < size; i++) {
                read >> type;

                if (type  == "class Boat") {
                    read >> make;
                    read >> model;
                    read >> nrOfPassengers;
                    read >> yearMade;
                    read >> width;
                    read >> length;
                    v = new Boat(make, model, yearMade, nrOfPassengers, width, length);

                } else if (type == "class Motorcycle") {
                    cout << "Blev en motorcykel, kör detta: " << endl;
                    read >> make;
                    read >> model;
                    read >> nrOfPassengers;
                    read >> yearMade;
                    read >> hp;
                    read >> cv;
                    v = new Motorcycle(make, model, yearMade, nrOfPassengers, hp, cv);
                }

                read.ignore();
                vector->add(v);
            }
        }

        read.close();

        return true;

    }

    bool save(MyVector<T> *&vector) const {

        // Filename empty? Dont save..
        if (this->filename.empty()) {
            return false;
        }

        ofstream out(this->filename);
        out << vector->getSize() << endl;
        out << vector->toString();
        out.close();

        return true;
    }

private:
    string filename;

};

#endif // FILEHANDLER_H
