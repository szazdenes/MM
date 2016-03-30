#include "plotform.h"
#include "ui_plotform.h"

PlotForm::PlotForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotForm)
{
    ui->setupUi(this);
}

PlotForm::~PlotForm()
{
    delete ui;
}

void PlotForm::mouseDoubleClickEvent(QMouseEvent *event)
{
    if((event->buttons() & Qt::LeftButton) != 0)
        emit signalMouseDoubleClicked();
    else
        QWidget::mousePressEvent(event);
}

void PlotForm::setPlottingParameters(QwtPlotCurve *curve, QVector<double> xdata, QVector<double> ydata, QwtText xtext, QwtText ytext)
{
    ui->qwtPlot->detachItems(QwtPlotItem::Rtti_PlotCurve);
    ui->qwtPlot->replot();

    if(!xdata.isEmpty() && !ydata.isEmpty()){

        ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, xtext);
        ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, ytext);
        curve->setRenderHint(QwtPlotItem::RenderAntialiased);
        curve->setSamples(xdata, ydata);
        curve->attach(ui->qwtPlot);
        ui->qwtPlot->setAxisScale(QwtPlot::xBottom, getXminXmax(xdata).first, getXminXmax(xdata).second);
        ui->qwtPlot->setAxisScale(QwtPlot::yLeft, getYminYmax(ydata).first, getYminYmax(ydata).second);
        ui->qwtPlot->replot();
    }
    else
        return;
}

QPair<double, double> PlotForm::getXminXmax(QVector<double> xvector)
{
    QVector<double> xlist = xvector;
    qSort(xlist.begin(), xlist.end());
    return QPair<double, double>(xlist.first(), xlist.last());
}

QPair<double, double> PlotForm::getYminYmax(QVector<double> yvector)
{
    QVector<double> ylist = yvector;
    qSort(ylist.begin(), ylist.end());
    return QPair<double, double>(ylist.first(), ylist.last());
}

void PlotForm::setPlotGrid()
{
    (new QwtPlotGrid())->attach(ui->qwtPlot);
}

void PlotForm::setZoomAndSpan()
{
    new QwtPlotPanner(ui->qwtPlot->canvas());

    QwtPlotMagnifier *mag1 = new QwtPlotMagnifier(ui->qwtPlot->canvas());
    mag1->setAxisEnabled(QwtPlot::yLeft, false);
    mag1->setAxisEnabled(QwtPlot::xBottom, true);

    QwtPlotMagnifier *mag2 = new QwtPlotMagnifier(ui->qwtPlot->canvas());
    mag2->setWheelModifiers(Qt::ControlModifier);
    mag2->setAxisEnabled(QwtPlot::xBottom, false);
    mag2->setAxisEnabled(QwtPlot::yLeft, true);
}

void PlotForm::setPlotPicker()
{
    new QwtPlotPicker(ui->qwtPlot->xBottom, ui->qwtPlot->yLeft, QwtPicker::CrossRubberBand, QwtPicker::AlwaysOn, ui->qwtPlot->canvas());
}
