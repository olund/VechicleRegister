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
    Boat first("yolo first", "a", 1, 1,1,1);

    boatVector.addLast(b);
    boatVector.addLast(c);
    boatVector.addLast(d);
    boatVector.addLast(e);
    boatVector.addFirst(first);
    boatVector.addLast(first);

    MyVector<int> intVector;
    intVector.addLast(1);
    intVector.addLast(2);
    intVector.addLast(3);

    //cout << intVector.toString();
    cout << "-------------------------------" << endl;
    cout << intVector[0] << endl;
    cout << boatVector[0] << endl;
    boatVector[0] = boatVector[3];
    cout << boatVector[0] << endl;



    //boatVector.print();
/*    delete v;
    delete vector;
*/
    return a.exec();
}
