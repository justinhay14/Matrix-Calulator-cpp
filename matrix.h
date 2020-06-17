#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <vector>

using std::vector;

class matrix
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
    matrix();
};

#endif // MATRIX_H
