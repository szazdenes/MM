#ifndef CALIBRATIONFORM_H
#define CALIBRATIONFORM_H

#include <QWidget>

namespace Ui {
class CalibrationForm;
}

class CalibrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit CalibrationForm(QWidget *parent = 0);
    ~CalibrationForm();

private:
    Ui::CalibrationForm *ui;
};

#endif // CALIBRATIONFORM_H
