#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Matrix.h"
#include <iostream>

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
    QTableWidget *table_ptr = ui->tableWidget;
    ui->tableWidget = ui->tableWidget_2;
    ui->tableWidget_2 = table_ptr;
}

void MainWindow::on_pushButton_10_clicked()
{
    QString function = ui->comboBox_2->currentText();
    if (function.startsWith("Determinant")) {
        vector<vector<double>> grid (ui->tableWidget->rowCount(), vector<double>(ui->tableWidget->columnCount(), 0));
        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
                grid[i][j] = ui->tableWidget->item(i, j)->text().toDouble();
            }
        }
        double answer = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid).determinant();
        QString text = "";
        text.setNum(answer);
        ui->textBrowser->setText(text);
    }
}

void MainWindow::on_pushButton_12_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{

}
// works
void MainWindow::on_pushButton_5_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() + 1);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount() + 1);
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount() + 1);
}
// works
void MainWindow::on_pushButton_6_clicked()
{
    if (ui->tableWidget->rowCount() != 1) {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
        ui->tableWidget->removeRow(ui->tableWidget->rowCount());
    }
    if (ui->tableWidget->columnCount() != 1) {
        ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() - 1);
        ui->tableWidget->removeColumn(ui->tableWidget->columnCount());
    }
}
// works
void MainWindow::on_pushButton_7_clicked()
{
    ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount() + 1);
    ui->tableWidget_2->setColumnCount(ui->tableWidget_2->columnCount() + 1);
    ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount() + 1);
    ui->tableWidget_2->insertColumn(ui->tableWidget_2->columnCount() + 1);
}
// works
void MainWindow::on_pushButton_8_clicked()
{
    if (ui->tableWidget_2->rowCount() != 1) {
        ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount() - 1);
        ui->tableWidget_2->removeRow(ui->tableWidget_2->rowCount());
    }
    if (ui->tableWidget_2->columnCount() != 1) {
        ui->tableWidget_2->setColumnCount(ui->tableWidget_2->columnCount() - 1);
        ui->tableWidget_2->removeColumn(ui->tableWidget_2->columnCount());
    }
}
