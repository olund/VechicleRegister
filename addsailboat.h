#ifndef ADDSAILBOAT_H
#define ADDSAILBOAT_H

#include <QDialog>
#include "sailboat.h"
#include "vehicle.h"

namespace Ui {
class addSailBoat;
}

class addSailBoat : public QDialog
{
    Q_OBJECT

public:
    explicit addSailBoat(QWidget *parent = 0);
    ~addSailBoat();

    Vehicle* add();


private:
    Ui::addSailBoat *ui;
};

#endif // ADDSAILBOAT_H
