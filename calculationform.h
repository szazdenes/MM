#ifndef CALCULATIONFORM_H
#define CALCULATIONFORM_H

#include <QWidget>
#include <QMatrix4x4>

#include "calculations.h"

namespace Ui {
class CalculationForm;
}

class CalculationForm : public QWidget
{
    Q_OBJECT

public:
    explicit CalculationForm(QWidget *parent = 0);
    ~CalculationForm();

public slots:
    void slotComputingMuellerMatrixReady();

private:
    Ui::CalculationForm *ui;
    Calculations* calc;
    QMatrix4x4 muellerMatrix;
};

#endif // CALCULATIONFORM_H
