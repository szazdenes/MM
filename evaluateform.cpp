#include "evaluateform.h"
#include "ui_evaluateform.h"

EvaluateForm::EvaluateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvaluateForm)
{
    ui->setupUi(this);

    connect(ui->ePlotWidget_01, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked1()));
    connect(ui->ePlotWidget_02, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked2()));
    connect(ui->ePlotWidget_03, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked3()));
    connect(ui->ePlotWidget_04, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked4()));
    connect(ui->ePlotWidget_05, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked5()));
    connect(ui->ePlotWidget_06, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked6()));
    connect(ui->ePlotWidget_07, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked7()));
    connect(ui->ePlotWidget_08, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked8()));
    connect(ui->ePlotWidget_09, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked9()));
    connect(ui->ePlotWidget_10, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked10()));
    connect(ui->ePlotWidget_11, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked11()));
    connect(ui->ePlotWidget_12, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked12()));
    connect(ui->ePlotWidget_13, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked13()));
    connect(ui->ePlotWidget_14, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked14()));
    connect(ui->ePlotWidget_15, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked15()));
    connect(ui->ePlotWidget_16, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked16()));

    connect(this, SIGNAL(signalAddMatrixHeaders(QStringList,QStringList)), ui->matrixWidget, SLOT(slotAddMatrixHeaders(QStringList,QStringList)));
    connect(this, SIGNAL(signalSendMatrixParameters(QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>)), ui->matrixWidget, SLOT(slotMatrixParameters(QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>,QVector<double>)));
    connect(ui->matrixWidget, SIGNAL(signalSendCurrentMatrixWavelength(int)), this, SLOT(slotCurrentMatrixWavelength(int)));

    QStringList vHeaders = QStringList() << "P1" << "P2" << "P3" << "P4";
    QStringList hHeaders = QStringList() << "A1" << "A2" << "A3" << "A4";

    emit signalAddMatrixHeaders(hHeaders, vHeaders);
}

EvaluateForm::~EvaluateForm()
{
    delete ui;
}

void EvaluateForm::slotMouseDoubleClicked1()
{
    IndividualPlotDialog dialog(QString("P1A1"), fx, fy1, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked2()
{
    IndividualPlotDialog dialog(QString("P1A2"), fx, fy2, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked3()
{
    IndividualPlotDialog dialog(QString("P1A3"), fx, fy3, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked4()
{
    IndividualPlotDialog dialog(QString("P1A4"), fx, fy4, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked5()
{
    IndividualPlotDialog dialog(QString("P2A1"), fx, fy5, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked6()
{
    IndividualPlotDialog dialog(QString("P2A2"), fx, fy6, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked7()
{
    IndividualPlotDialog dialog(QString("P2A3"), fx, fy7, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked8()
{
    IndividualPlotDialog dialog(QString("P2A4"), fx, fy8, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked9()
{
    IndividualPlotDialog dialog(QString("P3A1"), fx, fy9, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked10()
{
    IndividualPlotDialog dialog(QString("P3A2"), fx, fy10, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked11()
{
    IndividualPlotDialog dialog(QString("P3A3"), fx, fy11, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked12()
{
    IndividualPlotDialog dialog(QString("P3A4"), fx, fy12, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked13()
{
    IndividualPlotDialog dialog(QString("P4A1"), fx, fy13, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked14()
{
    IndividualPlotDialog dialog(QString("P4A2"), fx, fy14, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked15()
{
    IndividualPlotDialog dialog(QString("P4A3"), fx, fy15, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotMouseDoubleClicked16()
{
    IndividualPlotDialog dialog(QString("P4A4"), fx, fy16, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void EvaluateForm::slotCurrentMatrixWavelength(int wave)
{
    matrixWavelength = wave;
}


void EvaluateForm::on_magnifyToolButton_clicked()
{
    MatrixDialog dialog(matrixWavelength, fx, fy1, fy2, fy3, fy4, fy5, fy6, fy7, fy8, fy9, fy10, fy11, fy12, fy13, fy14, fy15, fy16, this);
    dialog.exec();
    connect(&dialog, SIGNAL(signalSendCurrentWavelength(int)), ui->matrixWidget, SLOT(slotSetSentWavelength(int)));
}

void EvaluateForm::on_pushButton_clicked()
{
    QFile inputFile(QFileDialog::getOpenFileName(this, tr("Open File")));

    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug("baj");

    QTextStream filestream(&inputFile);
    fx.clear();
    fy1.clear();
    fy2.clear();
    fy3.clear();
    fy4.clear();
    fy5.clear();
    fy6.clear();
    fy7.clear();
    fy8.clear();
    fy9.clear();
    fy10.clear();
    fy11.clear();
    fy12.clear();
    fy13.clear();
    fy14.clear();
    fy15.clear();
    fy16.clear();

    double x=0, y1=0, y2=0, y3=0, y4=0, y5=0, y6=0, y7=0, y8=0, y9=0, y10=0, y11=0, y12=0, y13=0, y14=0, y15=0, y16=0;


    QString line;

    for (int i=0; i<6; i++)
        line = filestream.readLine();

    while (!filestream.atEnd()){
        line = filestream.readLine();
        QTextStream stream(&line);
        stream >> x >> y1 >> y2 >> y3 >> y4 >> y5 >> y6 >> y7 >> y8 >> y9 >> y10 >> y11 >> y12 >> y13 >> y14 >> y15 >> y16;
        fx.append(x);
        fy1.append(y1);
        fy2.append(y2);
        fy3.append(y3);
        fy4.append(y4);
        fy5.append(y5);
        fy6.append(y6);
        fy7.append(y7);
        fy8.append(y8);
        fy9.append(y9);
        fy10.append(y10);
        fy11.append(y11);
        fy12.append(y12);
        fy13.append(y13);
        fy14.append(y14);
        fy15.append(y15);
        fy16.append(y16);
    }

    inputFile.close();

    ui->ePlotWidget_01->setPlottingParameters(new QwtPlotCurve(), fx, fy1, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_02->setPlottingParameters(new QwtPlotCurve(), fx, fy2, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_03->setPlottingParameters(new QwtPlotCurve(), fx, fy3, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_04->setPlottingParameters(new QwtPlotCurve(), fx, fy4, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_05->setPlottingParameters(new QwtPlotCurve(), fx, fy5, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_06->setPlottingParameters(new QwtPlotCurve(), fx, fy6, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_07->setPlottingParameters(new QwtPlotCurve(), fx, fy7, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_08->setPlottingParameters(new QwtPlotCurve(), fx, fy8, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_09->setPlottingParameters(new QwtPlotCurve(), fx, fy9, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_10->setPlottingParameters(new QwtPlotCurve(), fx, fy10, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_11->setPlottingParameters(new QwtPlotCurve(), fx, fy11, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_12->setPlottingParameters(new QwtPlotCurve(), fx, fy12, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_13->setPlottingParameters(new QwtPlotCurve(), fx, fy13, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_14->setPlottingParameters(new QwtPlotCurve(), fx, fy14, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_15->setPlottingParameters(new QwtPlotCurve(), fx, fy15, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->ePlotWidget_16->setPlottingParameters(new QwtPlotCurve(), fx, fy16, QwtText("Wavelength (nm)"), QwtText("Intensity"));

    emit signalSendMatrixParameters(fx, fy1, fy2, fy3, fy4, fy5, fy6, fy7, fy8, fy9, fy10, fy11, fy12, fy13, fy14, fy15, fy16);
}
