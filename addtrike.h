#ifndef ADDTRIKE_H
#define ADDTRIKE_H

#include <QDialog>
#include "vehicle.h"
#include "trike.h"

namespace Ui {
class AddTrike;
}

class AddTrike : public QDialog
{
    Q_OBJECT

public:
    explicit AddTrike(QWidget *parent = 0);
    ~AddTrike();
    Vehicle* addTrike();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddTrike *ui;
};

#endif // ADDTRIKE_H
