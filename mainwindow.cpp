#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_lineEdit_textChanged(const QString &theText)
{
    // 'Advanced search'
    std::cout << theText.toStdString() << std::endl;
    //std:: cout << ui->lineEdit->text().toStdString() << std::endl;
}
