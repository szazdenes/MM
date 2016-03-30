#include "spectrometerform.h"
#include "ui_spectrometerform.h"

SpectrometerForm::SpectrometerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpectrometerForm)
{
    ui->setupUi(this);

    measureSpectrum();
}

SpectrometerForm::~SpectrometerForm()
{
    delete ui;
}

QPair<QVector<double>, QVector<double> > SpectrometerForm::measureSpectrum()
{
    QPair<QVector<double>, QVector<double> > spectrumData;
   /* int number = sbapi_probe_devices();
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
    sbapi_spectrometer_set_integration_time_micros(id, spectrometerFeatureId, 0, 1000000.0);
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
    sbapi_close_device(id, 0);*/

    return spectrumData;
}
