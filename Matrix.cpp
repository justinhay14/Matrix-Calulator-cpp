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
        //cout << grid[i].capacity() << "\n";
    }
    grid.clear();
    //cout << grid.capacity() << "\n";
}

int main() {
    vector<vector<double>> vect{{1,2,3}, {4,5,6}};
    vector<vector<double>> vect1{{7,8},{9,10},{11,12}};
    Matrix A = Matrix(2, 2,vect);
    Matrix B = Matrix(2, 2,vect1);
    //A.print();
    Matrix C = A.multiply(B);
    //A.~Matrix();
    C.print();
    //B.~Matrix();
}
