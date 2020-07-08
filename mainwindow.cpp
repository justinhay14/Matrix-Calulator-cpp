#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableWidget_cellActivated(int row, int column)
{

}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_10_clicked()
{

}

void MainWindow::on_pushButton_12_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() + 1);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount() + 1);
}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->tableWidget->rowCount() != 1) {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount() - 1);
    }
    if (ui->tableWidget->columnCount() != 1) {
        ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() - 1);
        ui->tableWidget->insertColumn(ui->tableWidget->columnCount() - 1);
    }
}
