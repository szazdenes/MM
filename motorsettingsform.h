#ifndef MOTORSETTINGSFORM_H
#define MOTORSETTINGSFORM_H

#include "controller.h"

#include <QWidget>

namespace Ui {
class MotorSettingsForm;
}

class MotorSettingsForm : public QWidget
{
    Q_OBJECT

public:
    explicit MotorSettingsForm(QWidget *parent = 0);
    ~MotorSettingsForm();

private slots:
    void on_ledPushButton_toggled(bool checked);

    void on_motor1CalibratePushButton_clicked();

    void on_motor2CalibratePushButton_clicked();

    void on_motor1ForwardPushButton_clicked();

    void on_motor2ForwardPushButton_clicked();

    void on_motor1BackwardPushButton_clicked();

    void on_motor2BackwardPushButton_clicked();

    void on_motor1FreePushButton_clicked();

    void on_motor2FreePushButton_clicked();

    void on_motor1GoPushButton_clicked();

    void on_motor2GoPushButton_clicked();

private:
    Ui::MotorSettingsForm *ui;
    Controller* controller;
};

#endif // MOTORSETTINGSFORM_H
