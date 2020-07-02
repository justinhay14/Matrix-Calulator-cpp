#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

using std::vector;
using std::endl;
using std::cout;

class Matrix
{
private:
    int rows;
    int columns;
public:
    vector<vector<double>> grid;
    int get_rows() {
        return rows;
    }
    int get_columns() {
        return columns;
    }
    void set_rows(int rows) {
        this->rows = rows;
    }
    void set_columns(int columns) {
        this->columns = columns;
    }
    // works
    Matrix add(Matrix term) {
        if ((rows != term.get_rows()) || (columns != term.get_columns())) {
            return Matrix();
        }
        Matrix sum = Matrix(rows, columns, grid);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                sum.grid[i][j] = grid[i][j] + term.grid[i][j];
            }
        }
        return sum;
    }
    // works
    Matrix subtract(Matrix term) {
        if ((rows != term.get_rows()) || (columns != term.get_columns())) {
            return Matrix();
        }
        Matrix difference = Matrix(rows, columns, grid);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                difference.grid[i][j] = grid[i][j] - term.grid[i][j];
            }
        }
        return difference;
    }
    // works
    Matrix scalar_multiply(double scalar) {
        Matrix product = Matrix(rows, columns, grid);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                product.grid[i][j] = grid[i][j] * scalar;
            }
        }
        return product;
    }
    double determinant() {
        if (rows != columns) {
            return 0xffffffff;
        }
        double ans = 0;
        vector<double> row (columns, 0);
        vector<vector<double>> sub_grid (rows - 1, vector<double>(columns - 1, 0));
        Matrix sub = Matrix(rows - 1, columns - 1, sub_grid);
        if (rows == 2) {
            return grid[0][0] * grid[1][1] - grid[1][0] * grid[0][1];
        }
        else {
            for (int k = 0; k < rows; k++) {
                int sub_row = 0;
                for (int i = 1; i < rows; i++) {
                    int sub_col = 0;
                    for (int j = 0; j < rows; j++) {
                        if (j == k) {
                            continue;
                        }
                        sub.grid[sub_row][sub_col] = grid[i][j];
                        sub_col++;
                    }
                    sub_row++;
                }
                ans = ans + (pow(-1, k) * grid[0][k] * sub.determinant());
            }
        }
        return ans;
    }
    // works
    Matrix multiply(Matrix factor) {
        if (columns != factor.get_rows()) {
            return Matrix();
        }
        vector<double> row_grid (factor.get_columns(), 0.0);
        vector<vector<double>> prod_grid (rows, row_grid);
        Matrix product = Matrix(rows, factor.get_columns(), prod_grid);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                for (int k = 0; k < columns; k++) {
                    product.grid[i][j] += grid[i][k] * factor.grid[k][j];
                }
            }
        }
        return product;
    }
    // works
    Matrix transpose() {
        vector<double> ans_row (rows, 0);
        vector<vector<double>> ans_grid (columns, ans_row);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ans_grid[j][i] = grid[i][j];
            }
        }
        return Matrix(columns, rows, ans_grid);
    }
    // works
    Matrix rref() {
        vector<double> ans_row (columns, 0);
        vector<vector<double>> ans_grid (rows, ans_row);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ans_grid[i][j] = grid[i][j];
            }
        }
        int lead = 0;
        while (lead < rows) {
            for (int i = 0; i < rows; i++) {
                double div = ans_grid[lead][lead];
                double fact = ans_grid[i][lead] / ans_grid[lead][lead];
                for (int j = 0; j < columns; j++) {
                    if (i == lead) {
                        ans_grid[i][j] /= div;
                    }
                    else {
                        ans_grid[i][j] -= ans_grid[lead][j] * fact;
                    }
                }
            }
            lead++;
        }
        return Matrix(rows, columns, ans_grid);
    }
    // works
    Matrix inverse() {
        vector<double> manip_row (2 * columns, 0);
        vector<vector<double>> manip_grid (rows, manip_row);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 2 * columns; j++) {

                if (j >= columns && j - columns == i) {
                    manip_grid[i][j] = 1;
                }
                else if (j >= columns) {
                    manip_grid[i][j] = 0;
                }
                else {
                    manip_grid[i][j] = grid[i][j];
                }
            }
        }
        Matrix manip = Matrix(rows, 2 * columns, manip_grid);
        //manip.print();
        manip = manip.rref();
        //manip.print();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if ((manip.grid[i][j] != 0 && i != j) || (manip.grid[i][j] != 1 && i == j)) {
                    //manip.~Matrix();
                    return Matrix();
                }
            }
        }
        //cout << "passed\n";
        manip.set_columns(columns);
        for (int i = 0; i < rows; i++) {
            manip.grid[i].erase(manip.grid[i].begin(), manip.grid[i].begin() + columns);
            manip.grid[i].shrink_to_fit();
        }
        return manip;
    }
    // works
    void print() {
    	for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    Matrix();
    Matrix(int rows, int columns, vector<vector<double>> grid);
    ~Matrix();
};

#endif // MATRIX_H
