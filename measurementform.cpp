#include "measurementform.h"
#include "ui_measurementform.h"

MeasurementForm::MeasurementForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeasurementForm)
{
    ui->setupUi(this);
    ui->saveToolButton->setDisabled(true);

    calc = Calculations::getInstance();
    controller = Controller::getInstance();
    if(controller == 0)
        setEnabled(false);

    connect(ui->mPlotWidget_01, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked1()));
    connect(ui->mPlotWidget_02, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked2()));
    connect(ui->mPlotWidget_03, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked3()));
    connect(ui->mPlotWidget_04, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked4()));
    connect(ui->mPlotWidget_05, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked5()));
    connect(ui->mPlotWidget_06, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked6()));
    connect(ui->mPlotWidget_07, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked7()));
    connect(ui->mPlotWidget_08, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked8()));
    connect(ui->mPlotWidget_09, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked9()));
    connect(ui->mPlotWidget_10, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked10()));
    connect(ui->mPlotWidget_11, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked11()));
    connect(ui->mPlotWidget_12, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked12()));
    connect(ui->mPlotWidget_13, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked13()));
    connect(ui->mPlotWidget_14, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked14()));
    connect(ui->mPlotWidget_15, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked15()));
    connect(ui->mPlotWidget_16, SIGNAL(signalMouseDoubleClicked()), this, SLOT(slotMouseDoubleClicked16()));

}

MeasurementForm::~MeasurementForm()
{
    delete calc;
    delete controller;
    delete ui;
}

void MeasurementForm::slotMouseDoubleClicked1()
{
    IndividualPlotDialog dialog(QString("P1A1"), spectrum11.first, spectrum11.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked2()
{
    IndividualPlotDialog dialog(QString("P1A2"), spectrum12.first, spectrum12.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked3()
{
    IndividualPlotDialog dialog(QString("P1A3"), spectrum13.first, spectrum13.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked4()
{
    IndividualPlotDialog dialog(QString("P1A4"), spectrum14.first, spectrum14.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked5()
{
    IndividualPlotDialog dialog(QString("P2A1"), spectrum21.first, spectrum21.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked6()
{
    IndividualPlotDialog dialog(QString("P2A2"), spectrum22.first, spectrum22.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked7()
{
    IndividualPlotDialog dialog(QString("P2A3"), spectrum23.first, spectrum23.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked8()
{
    IndividualPlotDialog dialog(QString("P2A4"), spectrum24.first, spectrum24.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked9()
{
    IndividualPlotDialog dialog(QString("P3A1"), spectrum31.first, spectrum31.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked10()
{
    IndividualPlotDialog dialog(QString("P3A2"), spectrum32.first, spectrum32.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked11()
{
    IndividualPlotDialog dialog(QString("P3A3"), spectrum33.first, spectrum33.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked12()
{
    IndividualPlotDialog dialog(QString("P3A4"), spectrum34.first, spectrum34.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked13()
{
    IndividualPlotDialog dialog(QString("P4A1"), spectrum41.first, spectrum41.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked14()
{
    IndividualPlotDialog dialog(QString("P4A2"), spectrum42.first, spectrum42.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked15()
{
    IndividualPlotDialog dialog(QString("P4A3"), spectrum43.first, spectrum43.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotMouseDoubleClicked16()
{
    IndividualPlotDialog dialog(QString("P4A4"), spectrum44.first, spectrum44.second, QwtText("Wavelength (nm)"), QwtText("Intensity"), this);
    dialog.exec();
}

void MeasurementForm::slotReadyForMeasurement()
{
    setMotorsPosition(0,0);
}

void MeasurementForm::slotMotorsInPosition(int deg1, int deg2)
{
    if(deg1 == 0 && deg2 == 0){
//        darkSpectrum = measureSpectrum();
        emit signalDarkSpectrumReady();
    }
    if(deg1 == 45 && deg2 == 45){
//        spectrum11 = measureSpectrum();
        emit signalGetNextMotorPosition(45, 135);
    }
    if(deg1 == 45 && deg2 == 135){
//        spectrum12 = measureSpectrum();
        emit signalGetNextMotorPosition(45, 225);
    }
    if(deg1 == 45 && deg2 == 225){
//        spectrum13 = measureSpectrum();
        emit signalGetNextMotorPosition(45, 315);
    }
    if(deg1 == 45 && deg2 == 315){
//        spectrum14 = measureSpectrum();
        emit signalGetNextMotorPosition(135, 45);
    }
    if(deg1 == 135 && deg2 == 45){
//        spectrum21 = measureSpectrum();
        emit signalGetNextMotorPosition(135, 135);
    }
    if(deg1 == 135 && deg2 == 135){
//        spectrum22 = measureSpectrum();
        emit signalGetNextMotorPosition(135, 225);
    }
    if(deg1 == 135 && deg2 == 225){
//        spectrum23 = measureSpectrum();
        emit signalGetNextMotorPosition(135, 315);
    }
    if(deg1 == 135 && deg2 == 315){
//        spectrum24 = measureSpectrum();
        emit signalGetNextMotorPosition(225, 45);
    }
    if(deg1 == 225 && deg2 == 45){
//        spectrum31 = measureSpectrum();
        emit signalGetNextMotorPosition(225, 135);
    }
    if(deg1 == 225 && deg2 == 135){
//        spectrum32 = measureSpectrum();
        emit signalGetNextMotorPosition(225, 225);
    }
    if(deg1 == 225 && deg2 == 225){
//        spectrum33 = measureSpectrum();
        emit signalGetNextMotorPosition(225, 315);
    }
    if(deg1 == 225 && deg2 == 315){
//        spectrum34 = measureSpectrum();
        emit signalGetNextMotorPosition(315, 45);
    }
    if(deg1 == 315 && deg2 == 45){
//        spectrum41 = measureSpectrum();
        emit signalGetNextMotorPosition(315, 135);
    }
    if(deg1 == 315 && deg2 == 135){
//        spectrum42 = measureSpectrum();
        emit signalGetNextMotorPosition(315, 225);
    }
    if(deg1 == 315 && deg2 == 225){
//        spectrum43 = measureSpectrum();
        emit signalGetNextMotorPosition(315, 315);
    }
    if(deg1 == 315 && deg2 == 315){
//        spectrum44 = measureSpectrum();
        emit signalMeasurementReady();
    }
}

void MeasurementForm::slotNextMotorPosition(int deg1, int deg2)
{
    setMotorsPosition(deg1, deg2);
}

void MeasurementForm::slotMeasurementReady()
{
    disconnect(this, SIGNAL(signalMotorsInPosition(int,int)), this, SLOT(slotMotorsInPosition(int,int)));
    disconnect(this, SIGNAL(signalGetNextMotorPosition(int,int)), this, SLOT(slotNextMotorPosition(int,int)));
    disconnect(this, SIGNAL(signalDarkSpectrumReady()), this, SLOT(slotDarkSpectrumReady()));
    disconnect(this, SIGNAL(signalMeasurementReady()), this, SLOT(slotMeasurementReady()));

    controller->setLed(false);
    controller->motor1Goto(0);
    controller->motor2Goto(0);
    controller->motor1Free();
    controller->motor2Free();

    fillDemoSpectra();

    if(!spectrum11.second.isEmpty()){
        for(int i=0; i<spectrum11.second.size(); i++){
            spectrum11.second.replace(i, spectrum11.second.at(i)-darkSpectrum.second.at(i));
            spectrum12.second.replace(i, spectrum12.second.at(i)-darkSpectrum.second.at(i));
            spectrum13.second.replace(i, spectrum13.second.at(i)-darkSpectrum.second.at(i));
            spectrum14.second.replace(i, spectrum14.second.at(i)-darkSpectrum.second.at(i));
            spectrum21.second.replace(i, spectrum21.second.at(i)-darkSpectrum.second.at(i));
            spectrum22.second.replace(i, spectrum22.second.at(i)-darkSpectrum.second.at(i));
            spectrum23.second.replace(i, spectrum23.second.at(i)-darkSpectrum.second.at(i));
            spectrum24.second.replace(i, spectrum24.second.at(i)-darkSpectrum.second.at(i));
            spectrum31.second.replace(i, spectrum31.second.at(i)-darkSpectrum.second.at(i));
            spectrum32.second.replace(i, spectrum32.second.at(i)-darkSpectrum.second.at(i));
            spectrum33.second.replace(i, spectrum33.second.at(i)-darkSpectrum.second.at(i));
            spectrum34.second.replace(i, spectrum34.second.at(i)-darkSpectrum.second.at(i));
            spectrum41.second.replace(i, spectrum41.second.at(i)-darkSpectrum.second.at(i));
            spectrum42.second.replace(i, spectrum42.second.at(i)-darkSpectrum.second.at(i));
            spectrum43.second.replace(i, spectrum43.second.at(i)-darkSpectrum.second.at(i));
            spectrum44.second.replace(i, spectrum44.second.at(i)-darkSpectrum.second.at(i));
        }
    }

    ui->mPlotWidget_01->setPlottingParameters(new QwtPlotCurve(), spectrum11.first, spectrum11.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_02->setPlottingParameters(new QwtPlotCurve(), spectrum12.first, spectrum12.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_03->setPlottingParameters(new QwtPlotCurve(), spectrum13.first, spectrum13.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_04->setPlottingParameters(new QwtPlotCurve(), spectrum14.first, spectrum14.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_05->setPlottingParameters(new QwtPlotCurve(), spectrum21.first, spectrum21.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_06->setPlottingParameters(new QwtPlotCurve(), spectrum22.first, spectrum22.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_07->setPlottingParameters(new QwtPlotCurve(), spectrum23.first, spectrum23.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_08->setPlottingParameters(new QwtPlotCurve(), spectrum24.first, spectrum24.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_09->setPlottingParameters(new QwtPlotCurve(), spectrum31.first, spectrum31.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_10->setPlottingParameters(new QwtPlotCurve(), spectrum32.first, spectrum32.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_11->setPlottingParameters(new QwtPlotCurve(), spectrum33.first, spectrum33.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_12->setPlottingParameters(new QwtPlotCurve(), spectrum34.first, spectrum34.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_13->setPlottingParameters(new QwtPlotCurve(), spectrum41.first, spectrum41.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_14->setPlottingParameters(new QwtPlotCurve(), spectrum42.first, spectrum42.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_15->setPlottingParameters(new QwtPlotCurve(), spectrum43.first, spectrum43.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));
    ui->mPlotWidget_16->setPlottingParameters(new QwtPlotCurve(), spectrum44.first, spectrum44.second, QwtText("Wavelength (nm)"), QwtText("Intensity"));

    ui->measureToolButton->setEnabled(true);
    ui->measureToolButton->setStyleSheet("default");
    ui->saveToolButton->setEnabled(true);
    ui->saveToolButton->setIcon(QIcon(":/disk.png"));

}

void MeasurementForm::slotDarkSpectrumReady()
{
    controller->setLed(true);
    setMotorsPosition(45,45);
}

void MeasurementForm::on_saveToolButton_clicked()
{

}

void MeasurementForm::on_measureToolButton_clicked()
{
    ui->measureToolButton->setStyleSheet("background-color: red");
    ui->measureToolButton->setDisabled(true);
    ui->saveToolButton->setDisabled(true);

    darkSpectrum.first.clear(); darkSpectrum.second.clear();
    spectrum11.first.clear(); spectrum11.second.clear();
    spectrum12.first.clear(); spectrum12.second.clear();
    spectrum13.first.clear(); spectrum13.second.clear();
    spectrum14.first.clear(); spectrum14.second.clear();
    spectrum21.first.clear(); spectrum21.second.clear();
    spectrum22.first.clear(); spectrum22.second.clear();
    spectrum23.first.clear(); spectrum23.second.clear();
    spectrum24.first.clear(); spectrum24.second.clear();
    spectrum31.first.clear(); spectrum31.second.clear();
    spectrum32.first.clear(); spectrum32.second.clear();
    spectrum33.first.clear(); spectrum33.second.clear();
    spectrum34.first.clear(); spectrum34.second.clear();
    spectrum41.first.clear(); spectrum41.second.clear();
    spectrum42.first.clear(); spectrum42.second.clear();
    spectrum43.first.clear(); spectrum43.second.clear();
    spectrum44.first.clear(); spectrum44.second.clear();

    QMatrix4x4 A(1,0,0,1,0,1,1,0,1,1,1,0,1,1,1,1);
    QMatrix4x4 B(6,3,2,4,5,9,11,16,3,15,4,8,3,9,10,16);

    calc->computeMuellerMatrix(A, B);

    connect(this, SIGNAL(signalReadyForMeasurement()), this, SLOT(slotReadyForMeasurement()));
    connect(this, SIGNAL(signalMotorsInPosition(int,int)), this, SLOT(slotMotorsInPosition(int,int)));
    connect(this, SIGNAL(signalGetNextMotorPosition(int,int)), this, SLOT(slotNextMotorPosition(int,int)));
    connect(this, SIGNAL(signalDarkSpectrumReady()), this, SLOT(slotDarkSpectrumReady()));
    connect(this, SIGNAL(signalMeasurementReady()), this, SLOT(slotMeasurementReady()));

    emit signalReadyForMeasurement();
}

void MeasurementForm::setMotorsPosition(int deg1, int deg2)
{
    controller->motor1Goto(deg1);
    controller->motor2Goto(deg2);
    emit signalMotorsInPosition(deg1, deg2);
}

QPair<QVector<double>, QVector<double> > MeasurementForm::measureSpectrum()
{
    QPair<QVector<double>, QVector<double> > spectrumData;
    int number = sbapi_probe_devices();
    qDebug("%d", number);
    long* deviceIdArray = new long[number];
    number = sbapi_get_device_ids(deviceIdArray, number);
    if(number < 1)
        return spectrumData;

    int id = deviceIdArray[0];
    sbapi_open_device(id, 0);
    char name[256];
    sbapi_get_device_type(id, 0, name, 255);
    long serialFeatureId;
    sbapi_get_serial_number_features(id, 0, &serialFeatureId, 1);
    QString serialNumber;
    char serial[256];
    sbapi_get_serial_number(id, serialFeatureId, 0, serial, 255);
    serialNumber.append(serial);

    qDebug("%s", qPrintable(serialNumber));

    long spectrometerFeatureId;
    sbapi_get_spectrometer_features(id, 0, &spectrometerFeatureId, 1);
    sbapi_spectrometer_set_integration_time_micros(id, spectrometerFeatureId, 0, 100000.0);
    int length = sbapi_spectrometer_get_formatted_spectrum_length(id, spectrometerFeatureId, 0);
    double* x = new double[length];
    double* y = new double[length];

    sbapi_spectrometer_get_formatted_spectrum(id, spectrometerFeatureId, 0, y, length);
    sbapi_spectrometer_get_wavelengths(id, spectrometerFeatureId, 0, x, length);
    for(int i = 0; i < length; i++){
        spectrumData.first.append(x[i]);
        spectrumData.second.append(y[i]);
    }

    delete[] x;
    delete[] y;
    sbapi_close_device(id, 0);

    return spectrumData;
}

void MeasurementForm::fillDemoSpectra()
{
    QDir datdir = QString("/home/denes/Documents/Poma/Mueller/MuellerInstrument/spectra");
    QStringList filenames(datdir.entryList(QStringList(), QDir::Files | QDir::NoDotAndDotDot));
    QString line;
    double wave, spect;
    QList<int> num;
    num.append(1);
    num.append(2);
    num.append(3);
    num.append(4);
    num.append(5);
    num.append(6);
    num.append(7);
    num.append(8);
    num.append(9);
    num.append(10);
    num.append(11);
    num.append(12);
    num.append(13);
    num.append(14);
    num.append(15);
    num.append(16);

    std::random_shuffle(num.begin(), num.end());

    for(int i = 0; i < filenames.size(); i++){
        QFile file;
        if(i == 0)
            file.setFileName(datdir.absoluteFilePath(filenames.at(i)));
        if(i > 0)
            file.setFileName(datdir.absoluteFilePath(filenames.at(num.at(i-1))));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            qDebug("Demofiles open error");
        QTextStream filestream(&file);
        filestream.readLine();

        while (!filestream.atEnd()){
            line = filestream.readLine();
            QTextStream stream(&line);
            stream >> wave >> spect;
            if(i == 0){
                darkSpectrum.first.append(wave);
                darkSpectrum.second.append(spect);
            }
            if(i == 1){
                spectrum11.first.append(wave);
                spectrum11.second.append(spect);
            }
            if(i == 2){
                spectrum12.first.append(wave);
                spectrum12.second.append(spect);
            }
            if(i == 3){
                spectrum13.first.append(wave);
                spectrum13.second.append(spect);
            }
            if(i == 4){
                spectrum14.first.append(wave);
                spectrum14.second.append(spect);
            }
            if(i == 5){
                spectrum21.first.append(wave);
                spectrum21.second.append(spect);
            }
            if(i == 6){
                spectrum22.first.append(wave);
                spectrum22.second.append(spect);
            }
            if(i == 7){
                spectrum23.first.append(wave);
                spectrum23.second.append(spect);
            }
            if(i == 8){
                spectrum24.first.append(wave);
                spectrum24.second.append(spect);
            }
            if(i == 9){
                spectrum31.first.append(wave);
                spectrum31.second.append(spect);
            }
            if(i == 10){
                spectrum32.first.append(wave);
                spectrum32.second.append(spect);
            }
            if(i == 11){
                spectrum33.first.append(wave);
                spectrum33.second.append(spect);
            }
            if(i == 12){
                spectrum34.first.append(wave);
                spectrum34.second.append(spect);
            }
            if(i == 13){
                spectrum41.first.append(wave);
                spectrum41.second.append(spect);
            }
            if(i == 14){
                spectrum42.first.append(wave);
                spectrum42.second.append(spect);
            }
            if(i == 15){
                spectrum43.first.append(wave);
                spectrum43.second.append(spect);
            }
            if(i == 16){
                spectrum44.first.append(wave);
                spectrum44.second.append(spect);
            }
        }
        file.close();
    }
}
