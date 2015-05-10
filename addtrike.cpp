#include "addtrike.h"
#include "ui_addtrike.h"

AddTrike::AddTrike(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTrike)
{
    ui->setupUi(this);
}

AddTrike::~AddTrike()
{
    delete ui;
}

Vehicle* AddTrike::addTrike() {
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

void AddTrike::on_buttonBox_accepted()
{

}
