#ifndef MATRIXDIALOG_H
#define MATRIXDIALOG_H

#include <QDialog>

namespace Ui {
class MatrixDialog;
}

class MatrixDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MatrixDialog(int wave, QVector<double> fx, QVector<double> fy1, QVector<double> fy2, QVector<double> fy3, QVector<double> fy4, QVector<double> fy5, QVector<double> fy6, QVector<double> fy7, QVector<double> fy8, QVector<double> fy9, QVector<double> fy10, QVector<double> fy11, QVector<double> fy12, QVector<double> fy13, QVector<double> fy14, QVector<double> fy15, QVector<double> fy16, QWidget *parent = 0);
    ~MatrixDialog();

signals:
    void signalAddPopupMatrixHeaders(QStringList hHeaders, QStringList vHeaders);
    void signalSendMatrixParameters(QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>, QVector<double>);
    void signalSendStartingWavelength(int wave);
    void signalSendCurrentWavelength(int wave);

public slots:
    void slotCurrentWavelength(int wave);

private:
    Ui::MatrixDialog *ui;
    int currentWavelength;
};

#endif // MATRIXDIALOG_H
