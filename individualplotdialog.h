#ifndef INDIVIDUALPLOTDIALOG_H
#define INDIVIDUALPLOTDIALOG_H

#include <QDialog>
#include <qwt_plot_curve.h>

namespace Ui {
class IndividualPlotDialog;
}

class IndividualPlotDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IndividualPlotDialog(QString title, QVector<double> fx, QVector<double> fy, QwtText xtext, QwtText ytext, QWidget *parent = 0);
    ~IndividualPlotDialog();

signals:

public slots:

private:
    Ui::IndividualPlotDialog *ui;
};

#endif // INDIVIDUALPLOTDIALOG_H
