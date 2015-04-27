#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <string>
#include "vehicle.h"
#include "boat.h"
#include "myvector.h"
#include "sailboat.h"
#include "motorcycle.h"
#include "filehandler.h"

using namespace std;


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
