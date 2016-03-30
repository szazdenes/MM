#ifndef SPECTROMETERFORM_H
#define SPECTROMETERFORM_H

#include <QWidget>

#include <api/seabreezeapi/SeaBreezeAPI.h>

namespace Ui {
class SpectrometerForm;
}

class SpectrometerForm : public QWidget
{
    Q_OBJECT

public:
    explicit SpectrometerForm(QWidget *parent = 0);
    ~SpectrometerForm();

private:
    Ui::SpectrometerForm *ui;
    QPair<QVector<double>, QVector<double> > measureSpectrum();
};

#endif // SPECTROMETERFORM_H
