#ifndef MEASUREMENTONDIALOG_H
#define MEASUREMENTONDIALOG_H

#include <QDialog>

namespace Ui {
class MeasurementOnDialog;
}

class MeasurementOnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MeasurementOnDialog(QWidget *parent = 0);
    ~MeasurementOnDialog();

signals:

public slots:


private:
    Ui::MeasurementOnDialog *ui;

};

#endif // MEASUREMENTONDIALOG_H
