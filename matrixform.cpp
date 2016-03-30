#include "matrixform.h"
#include "ui_matrixform.h"

MatrixForm::MatrixForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatrixForm)
{
    ui->setupUi(this);

    ui->matrixTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->matrixTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MatrixForm::~MatrixForm()
{
    delete ui;
}

void MatrixForm::slotAddMatrixHeaders(QStringList hHeaders, QStringList vHeaders)
{
    ui->matrixTableWidget->setHorizontalHeaderLabels(hHeaders);
    ui->matrixTableWidget->setVerticalHeaderLabels(vHeaders);
}

void MatrixForm::slotMatrixParameters(QVector<double> x, QVector<double> y1, QVector<double> y2, QVector<double> y3, QVector<double> y4, QVector<double> y5, QVector<double> y6, QVector<double> y7, QVector<double> y8, QVector<double> y9, QVector<double> y10, QVector<double> y11, QVector<double> y12, QVector<double> y13, QVector<double> y14, QVector<double> y15, QVector<double> y16)
{
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

    fx = x;
    fy1 = y1;
    fy2 = y2;
    fy3 = y3;
    fy4 = y4;
    fy5 = y5;
    fy6 = y6;
    fy7 = y7;
    fy8 = y8;
    fy9 = y9;
    fy10 = y10;
    fy11 = y11;
    fy12 = y12;
    fy13 = y13;
    fy14 = y14;
    fy15 = y15;
    fy16 = y16;

    if(!fx.isEmpty()){
        ui->waveLengthSpinBox->setMinimum((int) floor(fx.first()));
        ui->waveLengthSpinBox->setMaximum((int) floor(fx.last()));
    }
}

void MatrixForm::slotSetSentWavelength(int wave)
{
    ui->waveLengthSpinBox->setValue(wave);
}

void MatrixForm::slotExportNewFile()
{
    QString filename(QFileDialog::getSaveFileName(this, tr("Export"), QDir::currentPath()));
    if(!filename.endsWith(".csv"))
        filename.append(".csv");
    exportFile.setFileName(filename);
    if (!exportFile.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug("baj");
    stream.setDevice(&exportFile);
    stream << "Mueller Matrix Polarimeter\n\n";

}

void MatrixForm::slotExportAppendFile()
{
    QString filename(QFileDialog::getOpenFileName(this, tr("Export"), QDir::currentPath()));
    exportFile.setFileName(filename);
    if (!exportFile.open(QIODevice::Append | QIODevice::Text))
        qDebug("baj");
    stream.setDevice(&exportFile);
}

void MatrixForm::on_waveLengthSpinBox_valueChanged(int arg1)
{
    QList<double> matrixElements = fillTheMatrix(arg1);
    if(!matrixElements.isEmpty()){
        ui->matrixTableWidget->setItem(0,0, new QTableWidgetItem(QString::number(matrixElements.at(0))));
        ui->matrixTableWidget->setItem(0,1, new QTableWidgetItem(QString::number(matrixElements.at(1))));
        ui->matrixTableWidget->setItem(0,2, new QTableWidgetItem(QString::number(matrixElements.at(2))));
        ui->matrixTableWidget->setItem(0,3, new QTableWidgetItem(QString::number(matrixElements.at(3))));
        ui->matrixTableWidget->setItem(1,0, new QTableWidgetItem(QString::number(matrixElements.at(4))));
        ui->matrixTableWidget->setItem(1,1, new QTableWidgetItem(QString::number(matrixElements.at(5))));
        ui->matrixTableWidget->setItem(1,2, new QTableWidgetItem(QString::number(matrixElements.at(6))));
        ui->matrixTableWidget->setItem(1,3, new QTableWidgetItem(QString::number(matrixElements.at(7))));
        ui->matrixTableWidget->setItem(2,0, new QTableWidgetItem(QString::number(matrixElements.at(8))));
        ui->matrixTableWidget->setItem(2,1, new QTableWidgetItem(QString::number(matrixElements.at(9))));
        ui->matrixTableWidget->setItem(2,2, new QTableWidgetItem(QString::number(matrixElements.at(10))));
        ui->matrixTableWidget->setItem(2,3, new QTableWidgetItem(QString::number(matrixElements.at(11))));
        ui->matrixTableWidget->setItem(3,0, new QTableWidgetItem(QString::number(matrixElements.at(12))));
        ui->matrixTableWidget->setItem(3,1, new QTableWidgetItem(QString::number(matrixElements.at(13))));
        ui->matrixTableWidget->setItem(3,2, new QTableWidgetItem(QString::number(matrixElements.at(14))));
        ui->matrixTableWidget->setItem(3,3, new QTableWidgetItem(QString::number(matrixElements.at(15))));
    }
    else{
        ui->matrixTableWidget->setItem(0,0, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(0,1, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(0,2, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(0,3, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(1,0, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(1,1, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(1,2, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(1,3, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(2,0, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(2,1, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(2,2, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(2,3, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(3,0, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(3,1, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(3,2, new QTableWidgetItem(QString("NaN")));
        ui->matrixTableWidget->setItem(3,3, new QTableWidgetItem(QString("NaN")));
    }
    emit signalSendCurrentMatrixWavelength(arg1);
}

QList<double> MatrixForm::fillTheMatrix(int wavelength)
{
    QList<double> matrixElements;
    if(!fx.isEmpty()){
        for(int i = 0; i < fx.size(); i++){
            if((int) floor(fx.at(i)) == wavelength){
                matrixElements.append(fy1.at(i));
                matrixElements.append(fy2.at(i));
                matrixElements.append(fy3.at(i));
                matrixElements.append(fy4.at(i));
                matrixElements.append(fy5.at(i));
                matrixElements.append(fy6.at(i));
                matrixElements.append(fy7.at(i));
                matrixElements.append(fy8.at(i));
                matrixElements.append(fy9.at(i));
                matrixElements.append(fy10.at(i));
                matrixElements.append(fy11.at(i));
                matrixElements.append(fy12.at(i));
                matrixElements.append(fy13.at(i));
                matrixElements.append(fy14.at(i));
                matrixElements.append(fy15.at(i));
                matrixElements.append(fy16.at(i));
                currentIndex = i;
                break;
            }
        }
        return matrixElements;
    }
    else
        return matrixElements;
}

void MatrixForm::on_exportPushButton_clicked()
{
    if(!fx.isEmpty()){
        ExportDialog dialog(this);
        connect(&dialog, SIGNAL(signalExportNewFile()), this, SLOT(slotExportNewFile()));
        connect(&dialog, SIGNAL(signalExportAppendFile()), this, SLOT(slotExportAppendFile()));
        dialog.exec();

        if(ui->matrixTableWidget->item(0,0)->text() == "NaN")
            stream << "Wavelength\t" << QString::number(ui->waveLengthSpinBox->value()) << "\n\n";
        else
            stream << "Wavelength\t" << QString::number(fx.at(currentIndex)) << "\n\n";
        stream << " \t" << "A1\t" << "A2\t" << "A3\t" << "A4\n";
        stream << "P1\t" << ui->matrixTableWidget->item(0,0)->text() + "\t" << ui->matrixTableWidget->item(0,1)->text() + "\t" << ui->matrixTableWidget->item(0,2)->text() + "\t" << ui->matrixTableWidget->item(0,3)->text() + "\n";
        stream << "P2\t" << ui->matrixTableWidget->item(1,0)->text() + "\t" << ui->matrixTableWidget->item(1,1)->text() + "\t" << ui->matrixTableWidget->item(1,2)->text() + "\t" << ui->matrixTableWidget->item(1,3)->text() + "\n";
        stream << "P3\t" << ui->matrixTableWidget->item(2,0)->text() + "\t" << ui->matrixTableWidget->item(2,1)->text() + "\t" << ui->matrixTableWidget->item(2,2)->text() + "\t" << ui->matrixTableWidget->item(2,3)->text() + "\n";
        stream << "P4\t" << ui->matrixTableWidget->item(3,0)->text() + "\t" << ui->matrixTableWidget->item(3,1)->text() + "\t" << ui->matrixTableWidget->item(3,2)->text() + "\t" << ui->matrixTableWidget->item(3,3)->text() + "\n\n";
        exportFile.close();
    }
    else
        return;
}
