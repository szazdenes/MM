#ifndef MEASUREMENTFORM_H
#define MEASUREMENTFORM_H

#include <QWidget>
#include <QMatrix4x4>
#include <api/seabreezeapi/SeaBreezeAPI.h>
#include <QFileDialog>
#include <QTextStream>
#include <QtAlgorithms>

#include "individualplotdialog.h"
#include "calculations.h"
#include "controller.h"

namespace Ui {
class MeasurementForm;
}

class MeasurementForm : public QWidget
{
    Q_OBJECT

public:
    explicit MeasurementForm(QWidget *parent = 0);
    ~MeasurementForm();

signals:
    void signalReadyForMeasurement();
    void signalMotorsInPosition(int deg1, int deg2);
    void signalGetNextMotorPosition(int deg1, int deg2);
    void signalDarkSpectrumReady();
    void signalMeasurementReady();

public slots:
    void slotMouseDoubleClicked1();
    void slotMouseDoubleClicked2();
    void slotMouseDoubleClicked3();
    void slotMouseDoubleClicked4();
    void slotMouseDoubleClicked5();
    void slotMouseDoubleClicked6();
    void slotMouseDoubleClicked7();
    void slotMouseDoubleClicked8();
    void slotMouseDoubleClicked9();
    void slotMouseDoubleClicked10();
    void slotMouseDoubleClicked11();
    void slotMouseDoubleClicked12();
    void slotMouseDoubleClicked13();
    void slotMouseDoubleClicked14();
    void slotMouseDoubleClicked15();
    void slotMouseDoubleClicked16();
    void slotReadyForMeasurement();
    void slotMotorsInPosition(int deg1, int deg2);
    void slotNextMotorPosition(int deg1, int deg2);
    void slotMeasurementReady();
    void slotDarkSpectrumReady();

private slots:
    void on_saveToolButton_clicked();

    void on_measureToolButton_clicked();

private:
    Ui::MeasurementForm *ui;
    Calculations* calc;
    Controller* controller;

    void setMotorsPosition(int deg1, int deg2);
    QPair<QVector<double>, QVector<double> > measureSpectrum();
    void fillDemoSpectra();

    QPair<QVector<double>, QVector<double> > spectrum11;
    QPair<QVector<double>, QVector<double> > spectrum12;
    QPair<QVector<double>, QVector<double> > spectrum13;
    QPair<QVector<double>, QVector<double> > spectrum14;
    QPair<QVector<double>, QVector<double> > spectrum21;
    QPair<QVector<double>, QVector<double> > spectrum22;
    QPair<QVector<double>, QVector<double> > spectrum23;
    QPair<QVector<double>, QVector<double> > spectrum24;
    QPair<QVector<double>, QVector<double> > spectrum31;
    QPair<QVector<double>, QVector<double> > spectrum32;
    QPair<QVector<double>, QVector<double> > spectrum33;
    QPair<QVector<double>, QVector<double> > spectrum34;
    QPair<QVector<double>, QVector<double> > spectrum41;
    QPair<QVector<double>, QVector<double> > spectrum42;
    QPair<QVector<double>, QVector<double> > spectrum43;
    QPair<QVector<double>, QVector<double> > spectrum44;
    QPair<QVector<double>, QVector<double> > darkSpectrum;
};

#endif // MEASUREMENTFORM_H
