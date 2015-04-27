#include "addsomething.h"
#include "ui_addsomething.h"

AddSomething::AddSomething(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSomething)
{
    ui->setupUi(this);



}

AddSomething::~AddSomething()
{
    delete ui;
}
