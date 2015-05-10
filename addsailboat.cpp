#include "addsailboat.h"
#include "ui_addsailboat.h"

addSailBoat::addSailBoat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSailBoat)
{
    ui->setupUi(this);
}


Vehicle* addSailBoat::add() {

    string make = ui->sailMakeTxt->text().toStdString();
    string model = ui->sailModelTxt->text().toStdString();
    int yearMade = ui->sailYearMadeTxt->text().toInt();
    int nrOfPassengers = ui->sailNrOfPassengersTxt->text().toInt();
    int width = ui->sailWidthTxt->text().toInt();
    int length = ui->sailLengthTxt->text().toInt();
    int sailArea = ui->sailSomethingTxt->text().toInt();


    return new SailBoat(make, model, yearMade, nrOfPassengers, width, length, sailArea);
}


addSailBoat::~addSailBoat()
{
    delete ui;
}
