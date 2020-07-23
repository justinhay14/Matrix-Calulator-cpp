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
    QTableWidgetItem *item = ui->tableWidget->takeItem(row, column);
    item->setTextAlignment(Qt::AlignHCenter);
    /*ui->tableWidget->setItem(row, column, item);
    cout << "completed\n";*/
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
        if (ui->tableWidget->rowCount() != ui->tableWidget->columnCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrix for this operation\n\n");
            return;
        }
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
        if (ui->tableWidget->rowCount() != ui->tableWidget->columnCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrix for this operation\n\n");
            return;
        }
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
    QString function = ui->comboBox_3->currentText();
    vector<vector<double>> grid (ui->tableWidget_2->rowCount(), vector<double>(ui->tableWidget_2->columnCount(), 0));
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget_2->columnCount(); j++) {
            bool satis = true;
            double val = ui->tableWidget_2->item(i, j)->text().toDouble(&satis);
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
        if (ui->tableWidget_2->rowCount() != ui->tableWidget_2->columnCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrix for this operation\n\n");
            return;
        }
        if (ui->tableWidget_2->rowCount() == 1 && ui->tableWidget_2->columnCount() == 1) {
            QString spec_case = "";
            spec_case.setNum(grid[0][0]);
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("det(B) = " + spec_case + "\n\n");
            return;
        }
        double answer = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount(), grid).determinant();
        QString text = "";
        text.setNum(answer);
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("det(B) = " + text + "\n\n");
    }
    else if (function.startsWith("Inverse")) {
        if (ui->tableWidget_2->rowCount() != ui->tableWidget_2->columnCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrix for this operation\n\n");
            return;
        }
        Matrix answer = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount(), grid).inverse();
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Inverse(B) = \n" + to_string(answer) + "\n");
    }
    else if (function.startsWith("Transpose")) {
        Matrix answer = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount(), grid).transpose();
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Transpose(B) = \n" + to_string(answer) + "\n");
    }
    else if (function.startsWith("Reduced Row Echelon Form")) {
        Matrix answer = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount(), grid).rref();
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("rref(B) = \n" + to_string(answer) + "\n");
    }
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
        if (ui->tableWidget->rowCount() != ui->tableWidget_2->rowCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrices for this operation\n\n");
            return;
        }
        ui->textBrowser->insertPlainText("A + B = \n" + to_string(A.add(B)) + "\n");
    }
    else if (function.startsWith("A - B")) {
        if (ui->tableWidget->rowCount() != ui->tableWidget_2->rowCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrices for this operation\n\n");
            return;
        }
        ui->textBrowser->insertPlainText("A - B = \n" + to_string(A.subtract(B)) + "\n");
    }
    else if (function.startsWith("B - A")) {
        if (ui->tableWidget->rowCount() != ui->tableWidget_2->rowCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrices for this operation\n\n");
            return;
        }
        ui->textBrowser->insertPlainText("B - A = \n" + to_string(B.subtract(A)) + "\n");
    }
    else if (function.startsWith("AB")) {
        if (ui->tableWidget->columnCount() != ui->tableWidget_2->rowCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrices for this operation\n\n");
            return;
        }
        ui->textBrowser->insertPlainText("AB = \n" + to_string(A.multiply(B)) + "\n");
    }
    else if (function.startsWith("BA")) {
        if (ui->tableWidget->rowCount() != ui->tableWidget_2->columnCount()) {
            QTextCursor cursor = QTextCursor(ui->textBrowser->document());
            ui->textBrowser->setTextCursor(cursor);
            ui->textBrowser->insertPlainText("Error! Please enter in valid matrices for this operation\n\n");
            return;
        }
        ui->textBrowser->insertPlainText("BA = \n" + to_string(B.multiply(A)) + "\n");
    }
}
// works
void MainWindow::on_pushButton_5_clicked()
{
    if (ui->tableWidget->columnCount() == ui->tableWidget->rowCount()) {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() + 1);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount() + 1);
        ui->tableWidget->insertColumn(ui->tableWidget->columnCount() + 1);
    }
    else if (ui->tableWidget->rowCount() < ui->tableWidget->columnCount()) {
        for (int i = ui->tableWidget->rowCount() + 1; i <= ui->tableWidget->columnCount(); i++) {
            ui->tableWidget->insertRow(i);
        }
        ui->tableWidget->setRowCount(ui->tableWidget->columnCount());
    }
    else {
        for (int i = ui->tableWidget->columnCount() + 1; i <= ui->tableWidget->rowCount(); i++) {
            ui->tableWidget->insertColumn(i);
        }
        ui->tableWidget->setColumnCount(ui->tableWidget->rowCount());
    }
    QString new_rows = "";
    new_rows.setNum(ui->tableWidget->rowCount());
    ui->lineEdit_5->setText(new_rows);
    QString new_columns = "";
    new_columns.setNum(ui->tableWidget->columnCount());
    ui->lineEdit_6->setText(new_columns);
}
// works
void MainWindow::on_pushButton_6_clicked()
{
    if (ui->tableWidget->columnCount() == ui->tableWidget->rowCount()) {
        if (ui->tableWidget->rowCount() != 1) {
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount() - 1);
            ui->tableWidget->removeRow(ui->tableWidget->rowCount());
        }
        if (ui->tableWidget->columnCount() != 1) {
            ui->tableWidget->setColumnCount(ui->tableWidget->columnCount() - 1);
            ui->tableWidget->removeColumn(ui->tableWidget->columnCount());
        }
    }
    else if (ui->tableWidget->rowCount() < ui->tableWidget->columnCount()) {
        for (int i = ui->tableWidget->columnCount(); i > ui->tableWidget->rowCount() + 1; i--) {
            ui->tableWidget->removeColumn(i);
        }
        ui->tableWidget->setColumnCount(ui->tableWidget->rowCount());
    }
    else {
        for (int i = ui->tableWidget->rowCount(); i > ui->tableWidget->columnCount() + 1; i--) {
            ui->tableWidget->removeRow(i);
        }
        ui->tableWidget->setRowCount(ui->tableWidget->columnCount());
    }
    QString new_rows = "";
    new_rows.setNum(ui->tableWidget->rowCount());
    ui->lineEdit_5->setText(new_rows);
    QString new_columns = "";
    new_columns.setNum(ui->tableWidget->columnCount());
    ui->lineEdit_6->setText(new_columns);
}
// works
void MainWindow::on_pushButton_7_clicked()
{
    if (ui->tableWidget_2->columnCount() == ui->tableWidget_2->rowCount()) {
        ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount() + 1);
        ui->tableWidget_2->setColumnCount(ui->tableWidget_2->columnCount() + 1);
        ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount() + 1);
        ui->tableWidget_2->insertColumn(ui->tableWidget_2->columnCount() + 1);
    }
    else if (ui->tableWidget_2->rowCount() < ui->tableWidget_2->columnCount()) {
        for (int i = ui->tableWidget_2->rowCount() + 1; i <= ui->tableWidget_2->columnCount(); i++) {
            ui->tableWidget_2->insertRow(i);
        }
        ui->tableWidget_2->setRowCount(ui->tableWidget_2->columnCount());
    }
    else {
        for (int i = ui->tableWidget_2->columnCount() + 1; i <= ui->tableWidget_2->rowCount(); i++) {
            ui->tableWidget_2->insertColumn(i);
        }
        ui->tableWidget_2->setColumnCount(ui->tableWidget_2->rowCount());
    }
    QString new_rows = "";
    new_rows.setNum(ui->tableWidget_2->rowCount());
    ui->lineEdit_7->setText(new_rows);
    QString new_columns = "";
    new_columns.setNum(ui->tableWidget_2->columnCount());
    ui->lineEdit_8->setText(new_columns);
}
// works
void MainWindow::on_pushButton_8_clicked()
{
    if (ui->tableWidget_2->columnCount() == ui->tableWidget_2->rowCount()) {
        if (ui->tableWidget_2->rowCount() != 1) {
            ui->tableWidget_2->setRowCount(ui->tableWidget_2->rowCount() - 1);
            ui->tableWidget_2->removeRow(ui->tableWidget_2->rowCount());
        }
        if (ui->tableWidget_2->columnCount() != 1) {
            ui->tableWidget_2->setColumnCount(ui->tableWidget_2->columnCount() - 1);
            ui->tableWidget_2->removeColumn(ui->tableWidget_2->columnCount());
        }
    }
    else if (ui->tableWidget_2->rowCount() < ui->tableWidget_2->columnCount()) {
        for (int i = ui->tableWidget_2->columnCount(); i > ui->tableWidget_2->rowCount() + 1; i--) {
            ui->tableWidget_2->removeColumn(i);
        }
        ui->tableWidget_2->setColumnCount(ui->tableWidget_2->rowCount());
    }
    else {
        for (int i = ui->tableWidget_2->rowCount(); i > ui->tableWidget_2->columnCount() + 1; i--) {
            ui->tableWidget_2->removeRow(i);
        }
        ui->tableWidget_2->setRowCount(ui->tableWidget_2->columnCount());
    }
    QString new_rows = "";
    new_rows.setNum(ui->tableWidget_2->rowCount());
    ui->lineEdit_7->setText(new_rows);
    QString new_columns = "";
    new_columns.setNum(ui->tableWidget_2->columnCount());
    ui->lineEdit_8->setText(new_columns);
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
    QString empty = "";
    ui->textBrowser->insertPlainText(empty.setNum(scalar) + "A = \n" + to_string(answer) + "\n");
}

void MainWindow::on_pushButton_11_clicked()
{
    if (ui->tableWidget->rowCount() != ui->tableWidget->columnCount()) {
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Error! Please enter in valid matrix for this operation\n\n");
        return;
    }
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
    int exp = ui->lineEdit_2->text().toInt(&ok);
    if (!ok) {
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
        return;
    }
    Matrix answer = Matrix(ui->tableWidget->rowCount(), ui->tableWidget->columnCount(), grid).power(exp);
    QTextCursor cursor = QTextCursor(ui->textBrowser->document());
    ui->textBrowser->setTextCursor(cursor);
    QString empty = "";
    empty.setNum(exp);
    empty = "^" + empty;
    ui->textBrowser->insertPlainText("A" + empty + " = \n" + to_string(answer) + "\n");
}

void MainWindow::on_lineEdit_5_editingFinished()
{
    bool is_ok = true;
    int val = ui->lineEdit_5->text().toInt(&is_ok);
    if (val < 1)
        return;
    if (is_ok) {
        int rows_i = ui->tableWidget->rowCount();
        if (val < rows_i) {
            for (int i = rows_i; i > val; i--) {
                ui->tableWidget->removeRow(i);
                ui->tableWidget->setRowCount(val);
            }
        }
        else if (val > rows_i) {
            for (int i = rows_i + 1; i <= val; i++) {
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setRowCount(val);
            }
        }
    }
}

void MainWindow::on_lineEdit_6_editingFinished()
{
    bool is_ok = true;
    int val = ui->lineEdit_6->text().toInt(&is_ok);
    if (val < 1)
        return;
    if (is_ok) {
        int rows_i = ui->tableWidget->columnCount();
        if (val < rows_i) {
            for (int i = rows_i; i > val; i--) {
                ui->tableWidget->removeColumn(i);
                ui->tableWidget->setColumnCount(val);
            }
        }
        else if (val > rows_i) {
            for (int i = rows_i + 1; i <= val; i++) {
                ui->tableWidget->insertColumn(i);
                ui->tableWidget->setColumnCount(val);
            }
        }
    }
}

void MainWindow::on_lineEdit_7_editingFinished()
{
    bool is_ok = true;
    int val = ui->lineEdit_7->text().toInt(&is_ok);
    if (val < 1)
        return;
    if (is_ok) {
        int rows_i = ui->tableWidget_2->rowCount();
        if (val < rows_i) {
            for (int i = rows_i; i > val; i--) {
                ui->tableWidget_2->removeRow(i);
                ui->tableWidget_2->setRowCount(val);
            }
        }
        else if (val > rows_i) {
            for (int i = rows_i + 1; i <= val; i++) {
                ui->tableWidget_2->insertRow(i);
                ui->tableWidget_2->setRowCount(val);
            }
        }
    }
}

void MainWindow::on_lineEdit_8_editingFinished()
{
    bool is_ok = true;
    int val = ui->lineEdit_8->text().toInt(&is_ok);
    if (val < 1)
        return;
    if (is_ok) {
        int rows_i = ui->tableWidget_2->columnCount();
        if (val < rows_i) {
            for (int i = rows_i; i > val; i--) {
                ui->tableWidget_2->removeColumn(i);
                ui->tableWidget_2->setColumnCount(val);
            }
        }
        else if (val > rows_i) {
            for (int i = rows_i + 1; i <= val; i++) {
                ui->tableWidget_2->insertColumn(i);
                ui->tableWidget_2->setColumnCount(val);
            }
        }
    }
}

void MainWindow::on_pushButton_14_clicked()
{
    if (ui->tableWidget_2->rowCount() != ui->tableWidget_2->columnCount()) {
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Error! Please enter in valid matrix for this operation\n\n");
        return;
    }
    QString function = ui->comboBox_2->currentText();
    vector<vector<double>> grid (ui->tableWidget_2->rowCount(), vector<double>(ui->tableWidget_2->columnCount(), 0));
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget_2->columnCount(); j++) {
            bool satis = true;
            double val = ui->tableWidget_2->item(i, j)->text().toDouble(&satis);
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
    int exp = ui->lineEdit_3->text().toInt(&ok);
    if (!ok) {
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
        return;
    }
    Matrix answer = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount(), grid).power(exp);
    QTextCursor cursor = QTextCursor(ui->textBrowser->document());
    ui->textBrowser->setTextCursor(cursor);
    QString empty = "";
    empty.setNum(exp);
    empty = "^" + empty;
    ui->textBrowser->insertPlainText("B" + empty + " = \n" + to_string(answer) + "\n");
}

void MainWindow::on_pushButton_13_clicked()
{
    QString function = ui->comboBox_2->currentText();
    vector<vector<double>> grid (ui->tableWidget_2->rowCount(), vector<double>(ui->tableWidget_2->columnCount(), 0));
    for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
        for (int j = 0; j < ui->tableWidget_2->columnCount(); j++) {
            bool satis = true;
            double val = ui->tableWidget_2->item(i, j)->text().toDouble(&satis);
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
    double scalar = ui->lineEdit_4->text().toDouble(&ok);
    if (!ok) {
        QTextCursor cursor = QTextCursor(ui->textBrowser->document());
        ui->textBrowser->setTextCursor(cursor);
        ui->textBrowser->insertPlainText("Error! Please enter in valid numbers in the table\n\n");
        return;
    }
    Matrix answer = Matrix(ui->tableWidget_2->rowCount(), ui->tableWidget_2->columnCount(), grid).scalar_multiply(scalar);
    QTextCursor cursor = QTextCursor(ui->textBrowser->document());
    ui->textBrowser->setTextCursor(cursor);
    QString empty = "";
    ui->textBrowser->insertPlainText(empty.setNum(scalar) + "B = \n" + to_string(answer) + "\n");
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    //QTableWidgetItem *item = ui->tableWidget->takeItem(row, column);
    //item->setTextAlignment(Qt::AlignHCenter);
    //ui->tableWidget->setItem(row, column, item);
    //cout << "completed\n";
}


void MainWindow::on_tableWidget_cellEntered(int row, int column)
{

}

void MainWindow::on_pushButton_2_clicked()
{
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
            double val = ui->tableWidget_2->item(i, j)->text().toDouble(&satis);
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

    if (A.get_rows() > B.get_rows()) {
        for (int i = A.get_rows(); i > B.get_rows(); i--) {
            ui->tableWidget->removeRow(i);
        }
        ui->tableWidget->setRowCount(B.get_rows());
        for (int i = B.get_rows() + 1; i <= A.get_rows(); i++) {
            ui->tableWidget_2->insertRow(i);
        }
        ui->tableWidget_2->setRowCount(A.get_rows());
    }
    else if (A.get_rows() < B.get_rows()) {
        for (int i = B.get_rows(); i > A.get_rows(); i--) {
            ui->tableWidget_2->removeRow(i);
        }
        ui->tableWidget_2->setRowCount(A.get_rows());
        for (int i = A.get_rows() + 1; i <= B.get_rows(); i++) {
            ui->tableWidget->insertRow(i);
        }
        ui->tableWidget->setRowCount(B.get_rows());
    }

    if (A.get_columns() > B.get_columns()) {
        for (int i = A.get_columns(); i > B.get_columns(); i--) {
            ui->tableWidget->removeColumn(i);
        }
        ui->tableWidget->setColumnCount(B.get_columns());
        for (int i = B.get_columns() + 1; i <= A.get_columns(); i++) {
            ui->tableWidget_2->insertColumn(i);
        }
        ui->tableWidget_2->setColumnCount(A.get_columns());
    }
    else if (A.get_columns() < B.get_columns()) {
        for (int i = B.get_columns(); i > A.get_columns(); i--) {
            ui->tableWidget_2->removeColumn(i);
        }
        ui->tableWidget_2->setColumnCount(A.get_columns());
        for (int i = A.get_columns() + 1; i <= B.get_columns(); i++) {
            ui->tableWidget->insertColumn(i);
        }
        ui->tableWidget->setColumnCount(B.get_columns());
    }
}
