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
        };
        grid[i].clear();
        grid[i].shrink_to_fit();
    }
    grid.resize(0);
    grid.shrink_to_fit();
}

/*int main() {
    vector<vector<double>> vect{{1, 1, 1}, {1,1,1}, {1,1,3}};
    vector<vector<double>> vect1{{0,0,0}, {0,1,5}, {0,0,0}};
    Matrix A = Matrix(3, 3,vect);
    Matrix B = Matrix(3, 3,vect1);
    A.print();
    B.print();
    Matrix C = A.subtract(B);
    //B.deposit(A);
    //A.~Matrix();
    C.print();
    //C.~Matrix();
    //B.~Matrix();
    //cout << A.determinant() << endl;
}*/
