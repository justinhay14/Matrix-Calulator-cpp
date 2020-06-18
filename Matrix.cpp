#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix()
{
    rows = 0;
    columns = 0;
    grid = vector<vector<double>>();
}
Matrix::Matrix(int rows, int columns, vector<vector<double>> grid) {
    this->rows = rows;
    this->columns = columns;
    this->grid = grid;
}
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = 0;
        }
        grid[i].clear();
        cout << grid[i].capacity() << "\n";
    }
    grid.clear();
    cout << grid.capacity() << "\n";
}

int main() {
    vector<vector<double>> vect{{1,2}, {0, 3}};
    Matrix A = Matrix(2, 2,vect);
    Matrix B = Matrix(2, 2,vect);
    A.print();
    Matrix C = A.scalar_multiply(2);
    //A.~Matrix();
    C.print();
    //B.~Matrix();
}
