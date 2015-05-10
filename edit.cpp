#include "edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);

    this->mainLayout = new QFormLayout();

    this->setLayout(this->mainLayout);
    this->setWindowTitle("Edit");
}

void edit::setTrikeLayout() {
    ui->label->setText("Edit trike");
    string names[] = {
        "Make",
        "Model",
        "Year made",
        "Nr of passengers",
        "Horse power",
        "Cylinder volume",
        "Something"
    };

    string values[] = {
        this->trike->getMake(),
        this->trike->getModel(),
        to_string(this->trike->getYearMade()),
        to_string(this->trike->getNrOfPassengers()),
        to_string(this->trike->getHorsePower()),
        to_string(this->trike->getCylindervolume()),
        to_string(this->trike->getSomething())
    };

    for (int i = 0; i < 7; i++) {
        this->lbls[i] = new QLabel(QString::fromStdString(names[i]));
        this->txts[i] = new QLineEdit(QString::fromStdString(values[i]));
        this->mainLayout->insertRow(i, this->lbls[i], this->txts[i]);
    }
}

void edit::setSailBoatLayout() {
    ui->label->setText("Edit Sailboat");
    string names[] = {
        "Make",
        "Model",
        "Year made",
        "Nr of passengers",
        "Width",
        "Length",
        "Sail area"
    };

    string values[] = {
        this->sailBoat->getMake(),
        this->sailBoat->getModel(),
        to_string(this->sailBoat->getYearMade()),
        to_string(this->sailBoat->getNrOfPassengers()),
        to_string(this->sailBoat->getWidth()),
        to_string(this->sailBoat->getLength()),
        to_string(this->sailBoat->getSailArea())
    };

    for (int i = 0; i < 7; i++) {
        this->lbls[i] = new QLabel(QString::fromStdString(names[i]));
        this->txts[i] = new QLineEdit(QString::fromStdString(values[i]));
        this->mainLayout->insertRow(i, this->lbls[i], this->txts[i]);
    }

}

void edit::setVehicle(Vehicle *v) {
    this->v = v;
}

void edit::setTrike(Vehicle *t) {
    this->trike = dynamic_cast<Trike*>(t);
}

void edit::setSailBoat(Vehicle *s) {
    this->sailBoat = dynamic_cast<SailBoat*>(s);
}

edit::~edit()
{
    delete ui;
}


Vehicle* edit::editSailBoat() {
    string make = this->txts[0]->text().toStdString();
    string model = this->txts[1]->text().toStdString();
    int yearMade = this->txts[2]->text().toInt();
    int nrOfPassengers = this->txts[3]->text().toInt();
    int width = this->txts[4]->text().toInt();
    int length = this->txts[5]->text().toInt();
    int sailArea = this->txts[6]->text().toInt();

    return new SailBoat(make, model, yearMade, nrOfPassengers, width, length, sailArea);
}

Vehicle* edit::editTrike() {
    string make = this->txts[0]->text().toStdString();
    string model =this->txts[1]->text().toStdString();
    int yearMade = this->txts[2]->text().toInt();
    int nrOfPassengers = this->txts[3]->text().toInt();
    int horsePower = this->txts[4]->text().toInt();
    int cylinderVolume = this->txts[5]->text().toInt();
    int something = this->txts[6]->text().toInt();
    return new Trike(make, model, yearMade, nrOfPassengers, horsePower, cylinderVolume, something);
}
