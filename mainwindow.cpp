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

}
