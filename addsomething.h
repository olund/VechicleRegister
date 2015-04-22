#ifndef ADDSOMETHING_H
#define ADDSOMETHING_H

#include <QDialog>

namespace Ui {
class AddSomething;
}

class AddSomething : public QDialog
{
    Q_OBJECT

public:
    explicit AddSomething(QWidget *parent = 0);
    ~AddSomething();

private:
    Ui::AddSomething *ui;
};

#endif // ADDSOMETHING_H
