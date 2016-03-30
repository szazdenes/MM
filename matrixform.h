#ifndef MATRIXFORM_H
#define MATRIXFORM_H

#include "exportdialog.h"

#include <QWidget>
#include <QtMath>
#include <QFileDialog>
#include <QTextStream>

namespace Ui {
class MatrixForm;
}

class MatrixForm : public QWidget
{
    Q_OBJECT

public:
    explicit MatrixForm(QWidget *parent = 0);
    ~MatrixForm();

signals:
    void signalSendCurrentMatrixWavelength(int wave);

public slots:
    void slotAddMatrixHeaders(QStringList hHeaders, QStringList vHeaders);
    void slotMatrixParameters(QVector<double> x, QVector<double> y1, QVector<double> y2, QVector<double> y3, QVector<double> y4, QVector<double> y5, QVector<double> y6, QVector<double> y7, QVector<double> y8, QVector<double> y9, QVector<double> y10, QVector<double> y11, QVector<double> y12, QVector<double> y13, QVector<double> y14, QVector<double> y15, QVector<double> y16);
    void slotSetSentWavelength(int wave);
    void slotExportNewFile();
    void slotExportAppendFile();

private slots:
    void on_waveLengthSpinBox_valueChanged(int arg1);

    void on_exportPushButton_clicked();

private:
    Ui::MatrixForm *ui;
    QVector<double> fx, fy1, fy2, fy3, fy4, fy5, fy6, fy7, fy8, fy9, fy10, fy11, fy12, fy13, fy14, fy15, fy16;

    QList<double> fillTheMatrix(int wavelength);
    QFile exportFile;
    QTextStream stream;
    int currentIndex;
};

#endif // MATRIXFORM_H
