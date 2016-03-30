#include "calculationform.h"
#include "ui_calculationform.h"

CalculationForm::CalculationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculationForm)
{
    ui->setupUi(this);

    calc = Calculations::getInstance();

    ui->muellerTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->muellerTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->itensityTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->itensityTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stokesBeforeTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stokesBeforeTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stokesAfterTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stokesAfterTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList vHeaders = QStringList() << "P1" << "P2" << "P3" << "P4";
    QStringList hHeaders = QStringList() << "A1" << "A2" << "A3" << "A4";

    ui->muellerTableWidget->setHorizontalHeaderLabels(hHeaders);
    ui->muellerTableWidget->setVerticalHeaderLabels(vHeaders);
    ui->itensityTableWidget->setHorizontalHeaderLabels(hHeaders);
    ui->itensityTableWidget->setVerticalHeaderLabels(vHeaders);
    ui->stokesBeforeTableWidget->setHorizontalHeaderLabels(hHeaders);
    ui->stokesBeforeTableWidget->setVerticalHeaderLabels(vHeaders);
    ui->stokesAfterTableWidget->setHorizontalHeaderLabels(hHeaders);
    ui->stokesAfterTableWidget->setVerticalHeaderLabels(vHeaders);

    connect(calc, SIGNAL(signalComputingMuellerMatrixReady()), this, SLOT(slotComputingMuellerMatrixReady()));
}

CalculationForm::~CalculationForm()
{
    delete ui;
}

void CalculationForm::slotComputingMuellerMatrixReady()
{
    muellerMatrix = calc->getMuellerMatrix();
    ui->muellerTableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(muellerMatrix(0,0))));
    ui->muellerTableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(muellerMatrix(0,1))));
    ui->muellerTableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(muellerMatrix(0,2))));
    ui->muellerTableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(muellerMatrix(0,3))));
    ui->muellerTableWidget->setItem(1, 0, new QTableWidgetItem(QString::number(muellerMatrix(1,0))));
    ui->muellerTableWidget->setItem(1, 1, new QTableWidgetItem(QString::number(muellerMatrix(1,1))));
    ui->muellerTableWidget->setItem(1, 2, new QTableWidgetItem(QString::number(muellerMatrix(1,2))));
    ui->muellerTableWidget->setItem(1, 3, new QTableWidgetItem(QString::number(muellerMatrix(1,3))));
    ui->muellerTableWidget->setItem(2, 0, new QTableWidgetItem(QString::number(muellerMatrix(2,0))));
    ui->muellerTableWidget->setItem(2, 1, new QTableWidgetItem(QString::number(muellerMatrix(2,1))));
    ui->muellerTableWidget->setItem(2, 2, new QTableWidgetItem(QString::number(muellerMatrix(2,2))));
    ui->muellerTableWidget->setItem(2, 3, new QTableWidgetItem(QString::number(muellerMatrix(2,3))));
    ui->muellerTableWidget->setItem(3, 0, new QTableWidgetItem(QString::number(muellerMatrix(3,0))));
    ui->muellerTableWidget->setItem(3, 1, new QTableWidgetItem(QString::number(muellerMatrix(3,1))));
    ui->muellerTableWidget->setItem(3, 2, new QTableWidgetItem(QString::number(muellerMatrix(3,2))));
    ui->muellerTableWidget->setItem(3, 3, new QTableWidgetItem(QString::number(muellerMatrix(3,3))));
}
