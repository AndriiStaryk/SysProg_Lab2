//
//  Matrix.cpp
//  lab2_xc
//
//  Created by Andrii Staryk on 20.09.2024.
//

#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new int[rows * cols];
    
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = 0;
    }
}

Matrix::~Matrix() {
    delete[] data;
}

int& Matrix::at(int row, int col) {
    return data[row * cols + col];
}

const int& Matrix::at(int row, int col) const {
    return data[row * cols + col];
}


void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << at(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
