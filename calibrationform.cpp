#include "calibrationform.h"
#include "ui_calibrationform.h"

CalibrationForm::CalibrationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalibrationForm)
{
    ui->setupUi(this);
}

CalibrationForm::~CalibrationForm()
{
    delete ui;
}
