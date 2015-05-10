#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include "myvector.h"
#include <fstream>
#include <string>
#include "vehicle.h"
#include "boat.h"
#include "motorcycle.h"
#include "sailboat.h"
#include "trike.h"

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

    void setFilename(string filename) {
        this->filename = filename;
    }

    bool read(MyVector<T> &vector) {
        //ifstream read(this->filename);
        ifstream read("data.txt");

        int size = 0;

        if (read.is_open()) {

            string make,
                model,
                type;

            int yearMade,
                nrOfPassengers,
                width,
                length,
                sailArea,
                something;

            int hp;
            int cv;

            // Read size
            read >> size;

            Vehicle *v = nullptr;

            // Read until we have no elements left
            for (int i = 0; i < size; i++) {
                read >> type;


                if (type == "5Trike") {


                    cout << "Blev en TRIKE, kör detta: " << endl;
                    read.ignore();
                    getline(read, make);
                    getline(read, model);

                    //read >> model;
                    read >> nrOfPassengers;
                    read >> yearMade;
                    read >> hp;
                    read >> cv;
                    read >> something;
                    v = new Trike(make, model, yearMade, nrOfPassengers, hp, cv, something);
                } else if (type == "8SailBoat") {
                    cout << "Blev en sailboat" << endl;
                    read.ignore();
                    getline(read, make);
                    getline(read, model);

                    //read >> model;
                    read >> yearMade;
                    read >> nrOfPassengers;
                    read >> width;
                    read >> length;
                    read >> sailArea;
                    v = new SailBoat(make, model, yearMade, nrOfPassengers, width, length, sailArea);
                } else {
                    cout << "Ingen typ hittades..." << endl;
                    return false;
                }

                //read.ignore();
                vector.add(v);
            }
        }

        read.close();

        return true;

    }

    bool save(MyVector<T> &vector) const {

        // Filename empty? Dont save..
        if (this->filename.empty()) {
            return false;
        }

        ofstream out(this->filename);
        //ofstream out("data.txt");

        out << vector.getSize() << endl;
        out << vector.toString();
        out.close();

        return true;
    }

private:
    string filename;

};

#endif // FILEHANDLER_H
