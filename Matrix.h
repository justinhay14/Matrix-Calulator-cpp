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
            return 0;
        }
        double ans = 0;
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
                        if (j != k) {
                            sub.grid[sub_row][sub_col] = grid[i][j];
                            sub_col++;
                        }
                    }
                    sub_row++;
                }
                ans = ans + (pow(-1, k) * grid[0][k] * sub.determinant());
            }
        }
        return ans;
    }

    Matrix multiply(Matrix factor) {
        if (columns != factor.get_rows()) {
            return Matrix();
        }
        vector<vector<double>> prod_grid (rows, vector<double> (factor.get_columns(), 0.0));
        Matrix product = Matrix(rows, factor.get_columns(), prod_grid);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < factor.get_columns(); j++) {
                for (int k = 0; k < columns; k++) {
                    product.grid[i][j] += grid[i][k] * factor.grid[k][j];
                }
            }
        }
        return product;
    }

    Matrix transpose() {
        vector<vector<double>> ans_grid (columns, vector<double> (rows, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ans_grid[j][i] = grid[i][j];
            }
        }
        return Matrix(columns, rows, ans_grid);
    }

    Matrix rref() {
        vector<vector<double>> ans_grid (rows, vector<double> (columns, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                ans_grid[i][j] = grid[i][j];
            }
        }

        for (int k = 0; k < rows; k++) {
            for (int i = 0; i < rows; i++) {
                double div = ans_grid[k][k];
                double fact = ans_grid[i][k] / ans_grid[k][k];
                for (int j = 0; j < columns; j++) {
                    if (i == k) {
                        ans_grid[i][j] /= div;
                    }
                    else {
                        ans_grid[i][j] -= ans_grid[k][j] * fact;
                    }
                }
            }
        }
        return Matrix(rows, columns, ans_grid);
    }

    Matrix inverse() {
        vector<vector<double>> manip_grid (rows, vector<double> (2 * columns, 0));
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
        manip = manip.rref();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if ((manip.grid[i][j] != 0 && i != j) || (manip.grid[i][j] != 1 && i == j)) {
                    return Matrix();
                }
            }
        }
        manip.set_columns(columns);
        for (int i = 0; i < rows; i++) {
            manip.grid[i].erase(manip.grid[i].begin(), manip.grid[i].begin() + columns);
            manip.grid[i].shrink_to_fit();
        }
        return manip;
    }

    Matrix power(int exp) {
        if (exp < 0 || rows != columns)
            return Matrix();
        else if (exp == 0) {
            vector<vector<double>> id_grid (rows, vector<double> (columns, 0));
            for (int i = 0; i < rows; i++) {
                id_grid[i][i] = 1;
            }
            return Matrix(rows, columns, id_grid);
        }
        Matrix answer = Matrix(rows, columns, grid);
        for (int i = 1; i < exp; i++) {
            answer = answer.multiply(answer);
        }
        return answer;
    }

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
