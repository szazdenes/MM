#include "motorsettingsform.h"
#include "ui_motorsettingsform.h"


MotorSettingsForm::MotorSettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MotorSettingsForm)
{
    ui->setupUi(this);
    controller = Controller::getInstance();
    if(controller == 0)
        setEnabled(false);
}

MotorSettingsForm::~MotorSettingsForm()
{
    delete controller;
    delete ui;
}

void MotorSettingsForm::on_ledPushButton_toggled(bool checked)
{
    controller->setLed(checked);
}

void MotorSettingsForm::on_motor1CalibratePushButton_clicked()
{
    controller->motor1Calibrate();
}

void MotorSettingsForm::on_motor2CalibratePushButton_clicked()
{
    controller->motor2Calibrate();
}

void MotorSettingsForm::on_motor1ForwardPushButton_clicked()
{
    controller->motor1Step(true);
}

void MotorSettingsForm::on_motor2ForwardPushButton_clicked()
{
    controller->motor2Step(true);
}

void MotorSettingsForm::on_motor1BackwardPushButton_clicked()
{
    controller->motor1Step(false);
}

void MotorSettingsForm::on_motor2BackwardPushButton_clicked()
{
    controller->motor2Step(false);
}

void MotorSettingsForm::on_motor1FreePushButton_clicked()
{
    controller->motor1Free();
}

void MotorSettingsForm::on_motor2FreePushButton_clicked()
{
    controller->motor2Free();
}

void MotorSettingsForm::on_motor1GoPushButton_clicked()
{
    controller->motor1Goto(ui->motor1DestinationSpinBox->value());
}

void MotorSettingsForm::on_motor2GoPushButton_clicked()
{
    controller->motor2Goto(ui->motor2DestinationSpinBox->value());
}
