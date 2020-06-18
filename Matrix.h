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
        Matrix product;
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
    Matrix multiply() {
        return Matrix();
    }
    void print_matrix() {
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
