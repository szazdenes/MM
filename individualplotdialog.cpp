#include "individualplotdialog.h"
#include "ui_individualplotdialog.h"

IndividualPlotDialog::IndividualPlotDialog(QString title, QVector<double> fx, QVector<double> fy, QwtText xtext, QwtText ytext, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IndividualPlotDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(title);
    ui->plotWidget->setPlottingParameters(new QwtPlotCurve(), fx, fy, xtext, ytext);
    ui->plotWidget->setPlotGrid();
    ui->plotWidget->setZoomAndSpan();
    ui->plotWidget->setPlotPicker();
}

IndividualPlotDialog::~IndividualPlotDialog()
{
    delete ui;
}
