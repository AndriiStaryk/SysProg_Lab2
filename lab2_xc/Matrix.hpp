//
//  Matrix.hpp
//  lab2_xc
//
//  Created by Andrii Staryk on 20.09.2024.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>
#include "SafeQueue.hpp"

class Matrix {
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    ~Matrix();
    void print() const;
    void bubbleSort();
    void mergeSort();
    
    void bubbleSortParallel();
    void mergeSortParallel();
    
    int& at(int row, int col);
    const int& at(int row, int col) const;

private:
    int* data;
    int rows;
    int cols;
};


#endif /* Matrix_hpp */
