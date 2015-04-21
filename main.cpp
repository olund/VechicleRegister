#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <string>
#include "vehicle.h"
#include "boat.h"
#include "myvector.h"

using namespace std;


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MyVector<Boat> boatVector;
    Boat b("b", "b", 1994, 3, 300, 200);
    Boat c("c", "b", 1994, 3, 300, 200);
    Boat d("d", "b", 1994, 3, 300, 200);
    Boat e("e", "b", 1994, 3, 300, 200);

    boatVector.addLast(b);
    boatVector.addLast(c);
    boatVector.addLast(d);
    boatVector.addLast(e);

    boatVector.print();
/*    delete v;
    delete vector;
*/
    return a.exec();
}
