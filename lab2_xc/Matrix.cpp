//
//  Matrix.cpp
//  lab2_xc
//
//  Created by Andrii Staryk on 20.09.2024.
//

#include "Matrix.hpp"
#include "Alghoritms.hpp"
#include <iostream>

int myRand(const int from, const int to) {
    return from + arc4random() % (to - from + 1);
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new int[rows * cols];
    
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = myRand(0, 1000);
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


void Matrix::bubbleSort() {
    for (int i = 0; i < rows; ++i) {
        ::bubbleSort(data + (i * cols), cols);
    }
}

void Matrix::mergeSort() {
    for (int i = 0; i < rows; ++i) {
        ::mergeSort(data + (i * cols), 0, cols - 1);
    }
}

void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        
        std::cout << "|\t";
        
        for (int j = 0; j < cols; ++j) {
            std::cout << at(i, j) << "\t";
        }
        
        std::cout << "\t|";
        std::cout << std::endl;
    }
}
