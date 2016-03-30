#include "matrixdialog.h"
#include "ui_matrixdialog.h"

MatrixDialog::MatrixDialog(int wave, QVector<double> fx, QVector<double> fy1, QVector<double> fy2, QVector<double> fy3, QVector<double> fy4, QVector<double> fy5, QVector<double> fy6, QVector<double> fy7, QVector<double> fy8, QVector<double> fy9, QVector<double> fy10, QVector<double> fy11, QVector<double> fy12, QVector<double> fy13, QVector<double> fy14, QVector<double> fy15, QVector<double> fy16, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixDialog)
{
    ui->setupUi(this);

    QStringList vHeaders = QStringList() << "Polarizer State 1" << "Polarizer State 2" << "Polarizer State 3" << "Polarizer State 4";
    QStringList hHeaders = QStringList() << "Analizer State 1" << "Analizer State 2" << "Analizer State 3" << "Analizer State 4";

    connect(this, SIGNAL(signalAddPopupMatrixHeaders(QStringList,QStringList)), ui->matrixWidget, SLOT(slotAddMatrixHeaders(QStringList,QStringList)));
    connect(this, SIGNAL(signalSendMatrixParameters(QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>)), ui->matrixWidget, SLOT(slotMatrixParameters(QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>)));
    connect(this, SIGNAL(signalSendStartingWavelength(int)), ui->matrixWidget, SLOT(slotSetSentWavelength(int)));
    connect(ui->matrixWidget, SIGNAL(signalSendCurrentMatrixWavelength(int)), this, SLOT(slotCurrentWavelength(int)));

    emit signalAddPopupMatrixHeaders(hHeaders, vHeaders);
    emit signalSendMatrixParameters(fx, fy1, fy2, fy3, fy4, fy5, fy6, fy7, fy8, fy9, fy10, fy11, fy12, fy13, fy14, fy15, fy16);
    emit signalSendStartingWavelength(wave);
}

MatrixDialog::~MatrixDialog()
{
    delete ui;
    emit signalSendCurrentWavelength(currentWavelength);
}

void MatrixDialog::slotCurrentWavelength(int wave)
{
    currentWavelength = wave;
}
