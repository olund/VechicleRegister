#include "addvehicle.h"
#include "ui_addvehicle.h"
#include <iostream>
#include "QLineEdit"


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

void AddVehicle::on_pushButton_clicked()
{
    QLineEdit *q = new QLineEdit();


    cout << "madder fakker" << endl;

    delete q;
}


void AddVehicle::on_buttonBox_accepted()
{
    // Add new Vehicle..

    cout << ui->txt_make->text().toStdString() << endl;
    cout << ui->txt_modell->text().toStdString() << endl;
    cout << ui->txt_something->text().toStdString() << endl;
    cout << ui->txt_somethingelse->text().toStdString() << endl;
    cout << "OK" << endl;



}
