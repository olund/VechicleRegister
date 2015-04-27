#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addvehicle.h"
#include "register.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineEdit_textChanged(const QString &theText);

    void on_pushButton_2_clicked();

    void on_actionSave_to_file_triggered();

    void on_actionLoad_from_file_triggered();

private:
    Ui::MainWindow *ui;
    AddVehicle *addVehicleWindow;
    Register vehicleRegister;

};

#endif // MAINWINDOW_H
