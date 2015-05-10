#ifndef ADDVEHICLE_H
#define ADDVEHICLE_H

#include <QDialog>
#include "vehicle.h"
#include "trike.h"

namespace Ui {
    class AddVehicle;
}

class AddVehicle : public QDialog
{
    Q_OBJECT

public:
    explicit AddVehicle(QWidget *parent = 0);
    ~AddVehicle();

public slots:
    Vehicle* addSailBoat();
    Vehicle* addTrike();


private slots:
    void on_trikeForm_accepted();
    void on_SailboatForm_accepted();

    void on_trikeForm_2_accepted();

private:
    Ui::AddVehicle *ui;
};

#endif // ADDVEHICLE_H
