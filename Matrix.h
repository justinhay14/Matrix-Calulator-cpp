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
    vector<vector<double> > grid;
    int get_rows() {
        return rows;
    }
    int get_columns() {
        return columns;
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
    Matrix multiply(Matrix factor) {
        if (columns != factor.get_rows()) {
            return Matrix();
        }
        vector<double> row_grid (factor.get_columns(), 0.0);
        vector<vector<double>> prod_grid (rows, row_grid);
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
