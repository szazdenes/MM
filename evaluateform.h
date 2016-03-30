#ifndef EVALUATEFORM_H
#define EVALUATEFORM_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <qwt_plot_curve.h>

#include "individualplotdialog.h"
#include "matrixdialog.h"

namespace Ui {
class EvaluateForm;
}

class EvaluateForm : public QWidget
{
    Q_OBJECT

public:
    explicit EvaluateForm(QWidget *parent = 0);
    ~EvaluateForm();

    /*QwtPlotCurve *curve1;     //in case of different colours and styles
    QwtPlotCurve *curve2;
    QwtPlotCurve *curve3;
    QwtPlotCurve *curve4;
    QwtPlotCurve *curve5;
    QwtPlotCurve *curve6;
    QwtPlotCurve *curve7;
    QwtPlotCurve *curve8;
    QwtPlotCurve *curve9;
    QwtPlotCurve *curve10;
    QwtPlotCurve *curve11;
    QwtPlotCurve *curve12;
    QwtPlotCurve *curve13;
    QwtPlotCurve *curve14;
    QwtPlotCurve *curve15;
    QwtPlotCurve *curve16;*/


signals:
    void signalShowIndividualPlot();
    void signalAddMatrixHeaders(QStringList hHeaders, QStringList vHeaders);
    void signalSendMatrixParameters(QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>);

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
    void slotCurrentMatrixWavelength(int wave);

private slots:
    void on_magnifyToolButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::EvaluateForm *ui;
    QVector<double> fx, fy1, fy2, fy3, fy4, fy5, fy6, fy7, fy8, fy9, fy10, fy11, fy12, fy13, fy14, fy15, fy16;
    int matrixWavelength;

};

#endif // EVALUATEFORM_H
