#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <iostream>
#include <vector>

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
    Matrix determinant() {
        return Matrix();
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
                double a = ans_grid[lead][lead];
                double b = ans_grid[i][lead] / ans_grid[lead][lead];
                for (int j = 0; j < columns; j++) {
                    if (i == lead) {
                        ans_grid[i][j] /= a;
                    }
                    else {
                        ans_grid[i][j] -= ans_grid[lead][j] * b;
                    }
                }
            }
            lead++;
        }
        return Matrix(rows, columns, ans_grid);
    }
    /*Matrix inverse() {
        vector<double> manip_row (2 * columns, 0);
        vector<vector<double>> manip_grid (rows, manip_row);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                manip_grid[i][j] = grid[i][j];
            }
        }
        Matrix manip = Matrix(rows, 2 * columns, manip_grid);
        manip.rref();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (manip_grid[i][j] != 0) {
                    manip.~Matrix();
                    return Matrix();
                }
            }
        }
        cout << "passed\n";
        manip.set_columns(columns);
        for (int i = 0; i < rows; i++) {
            manip.grid[i].erase(manip.grid[i].begin(), manip.grid[i].begin() + columns);
            manip.grid[i].shrink_to_fit();
        }
        return manip;
    }*/
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
