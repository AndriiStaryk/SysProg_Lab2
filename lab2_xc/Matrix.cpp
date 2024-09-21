//
//  Matrix.cpp
//  lab2_xc
//
//  Created by Andrii Staryk on 20.09.2024.
//

#include "Matrix.hpp"
#include "Alghoritms.hpp"
#include <iostream>
#include <thread>

int myRand(const int from, const int to) {
    return from + arc4random() % (to - from + 1);
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new int[rows * cols];
    
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = myRand(1, 1000000);
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    // Allocate memory for the new matrix's data
    data = new int[rows * cols];
    
    // Copy data from the source matrix to the new matrix
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = other.data[i];
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

 
//void Matrix::bubbleSortParallel() {
//    std::vector<std::thread> threads;
//    
//    for (int row = 0; row < rows; ++row) {
//        threads.emplace_back([this, row]() {
//            ::bubbleSort(data + (row * cols), cols);
//        });
//    }
//
//    for (auto& t : threads) {
//        t.join();
//    }
//}

void Matrix::bubbleSortParallel() {
    SafeQueue<int> rowQueue;
    
    // Fill the queue with row indices
    for (int i = 0; i < rows; ++i) {
        rowQueue.push(i);
    }
    
    // Vector to hold the threads
    std::vector<std::thread> threads;
    const int maxThreads = 4;
    
    // Worker function for each thread
    auto worker = [&]() {
        int rowIndex;
        while (rowQueue.pop(rowIndex)) {
            // Sort this row using bubble sort
            ::bubbleSort(data + rowIndex * cols, cols);
        }
    };
    
    // Create threads, ensuring that we have at most `maxThreads` running
    for (int i = 0; i < maxThreads; ++i) {
        threads.emplace_back(worker);
    }
    
    // Signal threads to stop after all rows have been processed
    rowQueue.signalStop();
    
    // Wait for all threads to finish
    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }
}

void Matrix::mergeSort() {
    for (int i = 0; i < rows; ++i) {
        ::mergeSort(data + (i * cols), 0, cols - 1);
    }
}


void Matrix::mergeSortParallel() {
    SafeQueue<int> rowQueue;
    
    // Fill the queue with row indices
    for (int i = 0; i < rows; ++i) {
        rowQueue.push(i);
    }
    
    // Vector to hold the threads
    std::vector<std::thread> threads;
    const int maxThreads = 4;
    
    // Worker function for each thread
    auto worker = [&]() {
        int rowIndex;
        while (rowQueue.pop(rowIndex)) {
            ::mergeSort(data + (rowIndex * cols), 0, cols - 1);
        }
    };
    
    // Create threads, ensuring that we have at most `maxThreads` running
    for (int i = 0; i < maxThreads; ++i) {
        threads.emplace_back(worker);
    }
    
    // Signal threads to stop after all rows have been processed
    rowQueue.signalStop();
    
    // Wait for all threads to finish
    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }
}

//void Matrix::mergeSortParallel() {
//    std::vector<std::thread> threads;
//    
//    for (int row = 0; row < rows; ++row) {
//        threads.emplace_back([this, row]() {
//            ::mergeSort(data + (row * cols), 0, cols - 1);
//        });
//    }
//
//    for (auto& t : threads) {
//        t.join();
//    }
//}



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
