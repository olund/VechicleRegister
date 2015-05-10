#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addvehicle.h"
#include "addtrike.h"
#include "addsailboat.h"
#include "register.h"
#include "QListWidgetItem"
#include "edit.h"

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
    void on_actionSave_to_file_triggered();
    void on_actionLoad_from_file_triggered();

    void refreshList();

    void on_btn_removeVehicle_clicked();

    void on_btn_info_clicked();

    void on_btn_addTrike_clicked();

    void on_btn_sailBoat_clicked();    
    void on_btn_edit_clicked();

private:
    Ui::MainWindow *ui;

    AddVehicle *addVehicleWindow;
    AddTrike *addTrikeWindow;
    addSailBoat *addSailBoatWindow;

    Register vehicleRegister;

};

#endif // MAINWINDOW_H
