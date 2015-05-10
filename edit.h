#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "QLineEdit"
#include "QVBoxLayout"
#include "vehicle.h"
#include "sailboat.h"
#include "trike.h"
#include "QLabel"
#include "QFormLayout"

using namespace std;

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = 0);
    ~edit();

    void setTrikeLayout();
    void setSailBoatLayout();
    void setVehicle(Vehicle *v);
    void setSailBoat(Vehicle *s);
    void setTrike(Vehicle *t);

    Vehicle* editTrike();
    Vehicle* editSailBoat();

private slots:


private:
    Ui::edit *ui;
    QFormLayout *mainLayout;

    SailBoat *sailBoat;
    Trike *trike;
    Vehicle* v;

    QLabel *lbls[7];
    QLineEdit *txts[7];
};

#endif // EDIT_H
