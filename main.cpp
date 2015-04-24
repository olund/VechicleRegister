#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <string>
#include "vehicle.h"
#include "boat.h"
#include "myvector.h"
#include "sailboat.h"

using namespace std;


int main(int argc, char *argv[]) {



    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MyVector<Boat> *v = new MyVector<Boat>();

    Vehicle *fan = new Boat("a", "a", 1,1,1,1);
    cout << fan->toString();

    v->add(new Boat("a", "b", 1,1,1,1));
    v->add(new Boat("b", "b", 1,1,1,1));

    cout << "-------------------------------" << endl;


    return a.exec();
}
