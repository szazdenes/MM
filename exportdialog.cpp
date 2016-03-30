#include "exportdialog.h"
#include "ui_exportdialog.h"

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
}

ExportDialog::~ExportDialog()
{
    delete ui;
}

void ExportDialog::on_pushButton_clicked()
{
    this->close();
    emit signalExportNewFile();
}

void ExportDialog::on_pushButton_2_clicked()
{
    this->close();
    emit signalExportAppendFile();
}
