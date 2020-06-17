#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <vector>

using std::vector;

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
        Matrix sum = term;
        return sum;
    }
    Matrix subtract(Matrix term) {
        Matrix difference = term;
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
    Matrix();
};

#endif // MATRIX_H
