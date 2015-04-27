#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "addvehicle.h"
#include "QFileDialog"
#include "QString"
#include <iostream>
#include <filehandler.h>
#include <vehicle.h>
#include <motorcycle.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;


    delete addVehicleWindow;
}



void MainWindow::on_lineEdit_textChanged(const QString &theText) {
    // 'Advanced search'
    //std::cout << theText.toStdString() << std::endl;
    ui->listWidget->addItem(theText);
    //std:: cout << ui->lineEdit->text().toStdString() << std::endl;
}

void MainWindow::on_pushButton_2_clicked() {
    // Modal approach.
    /*AddSomething window;
    window.setModal(true);
    window.exec();*/

    // Modalless approach
    addVehicleWindow = new AddVehicle(this);
    addVehicleWindow->show();
}

void MainWindow::on_actionSave_to_file_triggered()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));


    if (fileName != "") {
        // EXAMPLE DATA.
        this->vehicleRegister.vehicles->add(new Motorcycle("Yamaha", "R1000", 2015, 2, 100, 1000));
        this->vehicleRegister.vehicles->add(new Boat("UberBoat", "makeA", 1999, 5, 100, 1000));

        this->vehicleRegister.fileHandler->save(this->vehicleRegister.vehicles);
        cout << "saved to: " << fileName.toStdString() << endl;
    }
}

void MainWindow::on_actionLoad_from_file_triggered()
{
    // Load from file.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (fileName != "") {
        this->vehicleRegister.fileHandler->read(this->vehicleRegister.vehicles);
    }

    for (int i = 0; i < this->vehicleRegister.vehicles->getSize(); i++) {
        cout << this->vehicleRegister.vehicles[i].toString();

        //QString str = QString::fromStdString(this->vehicleRegister.vehicles[i]);
        //cout << "INNE I SKITEN: " << str.toStdString() << endl;
        //cout << str.toStdString() << endl;
        //ui->listWidget->addItem(str);
    }
}
