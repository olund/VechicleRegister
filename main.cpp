#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <string>
#include "vehicle.h"
#include "boat.h"

using namespace std;


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Vehicle *v = new Boat("make1", "model1", 1994, 5, 20, 100);

    cout << v->toString() << endl;

    delete v;

    return a.exec();
}
