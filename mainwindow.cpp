#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "addsomething.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;


    delete addSomethingDialog;
}



void MainWindow::on_lineEdit_textChanged(const QString &theText) {
    // 'Advanced search'
    std::cout << theText.toStdString() << std::endl;
    //std:: cout << ui->lineEdit->text().toStdString() << std::endl;
}

void MainWindow::on_pushButton_2_clicked() {
    // Modal approach.
    /*AddSomething window;
    window.setModal(true);
    window.exec();*/

    // Modalless approach
    addSomethingDialog = new AddSomething(this);
    addSomethingDialog->show();


}
