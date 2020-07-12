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

QString to_string(Matrix A) {
    QString ans = "";
    for (int i = 0; i < A.get_rows(); i++) {
        //ans += "[";
        for (int j = 0; j < A.get_columns(); j++) {
            QString base = "";
            ans += base.setNum(A.grid[i][j]);
            if (j == A.get_columns() - 1)
                ans += "\n";
            else
                ans += "\t";
        }
    }
    return ans;
}


void MainWindow::on_pushButton_10_clicked()
{
    QString function = ui->comboBox_2->currentText();
    vector<vector<double>> grid (ui->tableWidget->rowCount(), vector<double>(ui->tableWidget->columnCount(), 0));
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            bool satis = true;
            double val = ui->tableWidget->item(i, j)->text().toDouble(&satis);
            if (!satis) {
                QTextCursor cursor = QTextCursor(ui->textBrowser->document());
                ui->textBrowser->setTextCursor(cursor);
                ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
                return;
            }
            grid[i][j] = val;
        }
    }
    if (function.startsWith("Determinant")) {
        if (ui->tableWidget->rowCount() == 1 && ui->tableWidget->columnCount() == 1) {
            QString spec_case = "";
            spec_case.setNum(grid[0][0]);
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("det(A) = " + spec_case + "\n\n");
            return;
        }
        double answer = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid).determinant();
        QString text = "";
        text.setNum(answer);
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("det(A) = " + text + "\n\n");
    }
    else if (function.startsWith("Inverse")) {
        Matrix answer = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid).inverse();
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Inverse(A) = \n" + to_string(answer) + "\n");
    }
    else if (function.startsWith("Transpose")) {
        Matrix answer = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid).transpose();
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Transpose(A) = \n" + to_string(answer) + "\n");
    }
    else if (function.startsWith("Reduced Row Echelon Form")) {
        Matrix answer = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid).rref();
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("rref(A) = \n" + to_string(answer) + "\n");
    }
}

void MainWindow::on_pushButton_12_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    QString function = ui->comboBox->currentText();
    vector<vector<double>> grid_a (ui->tableWidget->rowCount(), vector<double>(ui->tableWidget->columnCount(), 0));
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            bool satis = true;
            double val = ui->tableWidget->item(i, j)->text().toDouble(&satis);
            if (!satis) {
                QTextCursor cursor = QTextCursor(ui->textBrowser->document());
                ui->textBrowser->setTextCursor(cursor);
                ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
                return;
            }
            grid_a[i][j] = val;
        }
    }
    Matrix A = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid_a);

    vector<vector<double>> grid_b (ui->tableWidget_2->rowCount(), vector<double>(ui->tableWidget_2->columnCount(), 0));
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget_2->columnCount(); j++) {
            bool satis = true;
            double val = ui->tableWidget->item(i, j)->text().toDouble(&satis);
            if (!satis) {
                QTextCursor cursor = QTextCursor(ui->textBrowser->document());
                ui->textBrowser->setTextCursor(cursor);
                ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
                return;
            }
            grid_b[i][j] = val;
        }
    }
    Matrix B = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount(), grid_b);

    QTextCursor cursor = QTextCursor(ui->textBrowser->document());
    ui->textBrowser->setTextCursor(cursor);
    if (function.startsWith("A + B")) {
        ui->textBrowser->insertPlainText("A + B = \n" + to_string(A.add(B)) + "\n");
    }
    else if (function.startsWith("A - B")) {
        ui->textBrowser->insertPlainText("A - B = \n" + to_string(A.subtract(B)) + "\n");
    }
    else if (function.startsWith("B - A")) {
        ui->textBrowser->insertPlainText("B - A = \n" + to_string(B.subtract(A)) + "\n");
    }
    else if (function.startsWith("AB")) {
        ui->textBrowser->insertPlainText("AB = \n" + to_string(A.multiply(B)) + "\n");
    }
    else if (function.startsWith("BA")) {
        ui->textBrowser->insertPlainText("BA = \n" + to_string(B.multiply(A)) + "\n");
    }
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
// works
void MainWindow::on_pushButton_9_clicked()
{
    QString function = ui->comboBox_2->currentText();
    vector<vector<double>> grid (ui->tableWidget->rowCount(), vector<double>(ui->tableWidget->columnCount(), 0));
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget->columnCount(); j++) {
            bool satis = true;
            double val = ui->tableWidget->item(i, j)->text().toDouble(&satis);
            if (!satis) {
                QTextCursor cursor = QTextCursor(ui->textBrowser->document());
                ui->textBrowser->setTextCursor(cursor);
                ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
                return;
            }
            grid[i][j] = val;
        }
    }
    bool ok = true;
    double scalar = ui->lineEdit->text().toDouble(&ok);
    if (!ok) {
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
        return;
    }
    Matrix answer = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid).scalar_multiply(scalar);
    QTextCursor cursor = QTextCursor(ui->textBrowser->document());
    ui->textBrowser->setTextCursor(cursor);
    ui->textBrowser->insertPlainText("A = \n" + to_string(answer) + "\n");
}
