#include "measurementondialog.h"
#include "ui_measurementondialog.h"

MeasurementOnDialog::MeasurementOnDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MeasurementOnDialog)
{
    ui->setupUi(this);
    this->close();
}

MeasurementOnDialog::~MeasurementOnDialog()
{
    delete ui;
}
