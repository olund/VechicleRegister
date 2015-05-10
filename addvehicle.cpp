#include "addvehicle.h"
#include "ui_addvehicle.h"
#include <iostream>
#include "QLineEdit"
#include "mainwindow.h"


using namespace std;


AddVehicle::AddVehicle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVehicle)
{
    ui->setupUi(this);

}

AddVehicle::~AddVehicle()
{
    delete ui;
}



Vehicle* AddVehicle::addSailBoat() {

    string make = ui->sailMakeTxt->text().toStdString();
    string model = ui->sailModelTxt->text().toStdString();
    int yearMade = ui->sailYearMadeTxt->text().toInt();
    int nrOfPassengers = ui->sailNrOfPassengersTxt->text().toInt();
    int width = ui->sailWidthTxt->text().toInt();
    int length = ui->sailLengthTxt->text().toInt();
    int sailArea = ui->sailSomethingTxt->text().toInt();


    return new SailBoat(make, model, yearMade, nrOfPassengers, width, length, sailArea);
}

Vehicle* AddVehicle::addTrike() {
    //string make, string model, int yearMade, int nrOfPassgengers, int horsePower, int cylinderVolume, int something
    string make = ui->txt_make->text().toStdString();
    string model = ui->txt_modell->text().toStdString();
    int yearMade = ui->txt_yearMade->text().toInt();
    int nrOfPassengers = ui->txt_nrOfPassengers->text().toInt();
    int horsePower = ui->txt_horsePower->text().toInt();
    int cylinderVolume = ui->txt_cylinderVolume->text().toInt();
    int something = ui->txt_something->text().toInt();

    return new Trike(make, model, yearMade, nrOfPassengers, horsePower, cylinderVolume, something);

}


void AddVehicle::on_trikeForm_accepted()
{
    cout << "Sparade en trike" << endl;
    //this->addTrike();
}

void AddVehicle::on_SailboatForm_accepted()
{
    cout << "Sparade en Sailboat" << endl;
    //this->addSailBoat();
}

void AddVehicle::on_trikeForm_2_accepted()
{
    cout << "Sparade en trike" << endl;
    //this->addTrike();
}
