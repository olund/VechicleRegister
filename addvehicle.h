#ifndef ADDVEHICLE_H
#define ADDVEHICLE_H

#include <QDialog>

namespace Ui {
    class AddVehicle;
}

class AddVehicle : public QDialog
{
    Q_OBJECT

public:
    explicit AddVehicle(QWidget *parent = 0);
    ~AddVehicle();

private slots:

    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::AddVehicle *ui;
};

#endif // ADDVEHICLE_H
