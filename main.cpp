#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <string>
#include "vehicle.h"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Vehicle *v = new Vehicle();

    cout << v->getMake() << endl;

    return a.exec();
}
