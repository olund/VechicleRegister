#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "addvehicle.h"
#include "QFileDialog"
#include "QString"
#include "QMessageBox"
#include <iostream>
#include <filehandler.h>
#include <vehicle.h>
#include <motorcycle.h>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // ADD EXAMPLE VEHICLES...............
    this->vehicleRegister.getVehicles().add(new SailBoat("Najad Yachts", "Model A", 1,1,1,1,1));
    this->vehicleRegister.getVehicles().add(new SailBoat("Hallberg-Rassy", "Model B", 1,1,1,1,1));
    this->vehicleRegister.getVehicles().add(new Trike("Harley davidsson", "ModelEx", 2015, 1, 399, 750, 100));
    this->vehicleRegister.getVehicles().add(new SailBoat("Jensen Marine", "Model C", 1,1,1,1,1));

    this->refreshList();
}


MainWindow::~MainWindow() {
    delete ui;
    /*delete addVehicleWindow;
    delete addTrikeWindow;
    delete addSailBoatWindow;*/
}

void MainWindow::refreshList() {
    ui->vehicleList->clear();

    for (int i = 0; i < this->vehicleRegister.getVehicles().getSize(); i++) {
        string s = this->vehicleRegister.getVehicles().elementAt(i).getMake() + " - " + this->vehicleRegister.getVehicles().elementAt(i).getModel();
        ui->vehicleList->addItem(QString::fromStdString(s));
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &theText) {
    // 'Advanced search'
    string search = theText.toStdString();
    MyVector<string> vStr;

    for (int i = 0; i < ui->vehicleList->count(); i++) {
        string item = ui->vehicleList->item(i)->text().toStdString();

        if (!search.empty() && item.find(search) != string::npos) {
            vStr.add(item);
        }
    }

    ui->vehicleList->clear();
    if (vStr.getSize() == 0) {
        this->refreshList();
    } else {
        //add the new found items to the view.
        for (int i = 0; i < vStr.getSize(); i++) {
            try {
                ui->vehicleList->addItem(QString::fromStdString(vStr[i]));
            } catch (char *e) {
                cout << e << endl;
            }
        }
    }
}

void MainWindow::on_actionSave_to_file_triggered() {

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                tr("Text Files (*.txt)"));


    if (fileName != "") {
        this->vehicleRegister.getFileHandler().setFilename(fileName.toStdString());

        if (this->vehicleRegister.getFileHandler().save(this->vehicleRegister.getVehicles())) {
            cout << "saved to: " << fileName.toStdString() << endl;
        } else {
            cout << "Something bad happened with saving to file..." << endl;
        }
    }

    this->refreshList();
}

void MainWindow::on_actionLoad_from_file_triggered() {
    // Load from file.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt)"));

    if (fileName != "") {
        this->vehicleRegister.getFileHandler().setFilename(fileName.toStdString());
        this->vehicleRegister.getFileHandler().read(this->vehicleRegister.getVehicles());
    }

    this->refreshList();
}

void MainWindow::on_btn_removeVehicle_clicked() {

    int pos = this->vehicleRegister.findVehicle(ui->vehicleList->currentItem()->text().toStdString());
    //int pos = ui->vehicleList->currentRow();
    cout << "POS: " << pos << endl;



    if (pos != -1) {
        this->vehicleRegister.getVehicles().removeAt(pos);
    }

    this->refreshList();
}

void MainWindow::on_btn_info_clicked() {

    int pos = ui->vehicleList->currentRow();
    if (pos > -1) {
        QMessageBox::information(this, "Vehicle", QString::fromStdString(this->vehicleRegister.getVehicles().elementAt(pos).toString()));
    } else {
        QMessageBox::information(this, "No vehicle selected..", "No vehicle selected..");
    }

}

void MainWindow::on_btn_addTrike_clicked() {
    addTrikeWindow = new AddTrike(this);
    addTrikeWindow->show();

    if (addTrikeWindow->exec() == QDialog::Accepted) {
        this->vehicleRegister.getVehicles().add(addTrikeWindow->addTrike());
        this->refreshList();
    }

    delete addTrikeWindow;
}

void MainWindow::on_btn_sailBoat_clicked() {
    addSailBoatWindow = new addSailBoat(this);
    addSailBoatWindow->show();

    if (addSailBoatWindow->exec() == QDialog::Accepted) {
        this->vehicleRegister.getVehicles().add(addSailBoatWindow->add());
        this->refreshList();
    }

    delete addSailBoatWindow;
}

void MainWindow::on_btn_edit_clicked() {

    int pos = this->vehicleRegister.findVehicle(ui->vehicleList->currentItem()->text().toStdString());
    //int pos = ui->vehicleList->currentRow();

    if (pos != -1) {

        // Edit vehicle here...
        //cout << this->vehicleRegister.getVehicles()[pos].toString();

        if (this->vehicleRegister.getVehicles()[pos].getType() == "trike") {
            edit editWindow(this);
            editWindow.setTrike(this->vehicleRegister.getVehicles().getAt(pos));
            editWindow.setTrikeLayout();

            if (editWindow.exec() == QDialog::Accepted) {
                this->vehicleRegister.getVehicles().update(editWindow.editTrike(), pos);
            }

        } else if (this->vehicleRegister.getVehicles()[pos].getType() == "sailboat") {
            edit editWindow(this);
            editWindow.setSailBoat(this->vehicleRegister.getVehicles().getAt(pos));
            editWindow.setSailBoatLayout();

            if (editWindow.exec() == QDialog::Accepted) {
                this->vehicleRegister.getVehicles().update(editWindow.editSailBoat(), pos);
            }

        } else {
            // NO TYPE AVAILABLE.
        }

    }

    this->refreshList();
    cout << pos << endl;
}
