#ifndef PLOTFORM_H
#define PLOTFORM_H

#include <QWidget>
#include <QMouseEvent>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include <QtAlgorithms>

namespace Ui {
class PlotForm;
}

class PlotForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlotForm(QWidget *parent = 0);
    ~PlotForm();

    void mouseDoubleClickEvent(QMouseEvent *event);

    void setPlottingParameters(QwtPlotCurve *curve,
                               QVector<double> xdata,
                               QVector<double> ydata,
                               QwtText xtext,
                               QwtText ytext);
    QPair<double, double> getXminXmax(QVector<double> xvector);
    QPair<double, double> getYminYmax(QVector<double> yvector);
    void setPlotGrid();
    void setZoomAndSpan();
    void setPlotPicker();

signals:
    void signalMouseDoubleClicked();

private:
    Ui::PlotForm *ui;
};

#endif // PLOTFORM_H
