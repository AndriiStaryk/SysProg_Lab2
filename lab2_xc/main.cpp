//
//  main.cpp
//  lab2_xc
//
//  Created by Andrii Staryk on 20.09.2024.
//

#include "Matrix.hpp"
#include "Alghoritms.hpp"
#include <iostream>	

int main(int argc, const char * argv[]) {
    
    Matrix m = Matrix(1000, 4000);
    Matrix m1 = Matrix(m);
    Matrix m2 = Matrix(m);
    Matrix m3 = Matrix(m);
    Matrix m4 = Matrix(m);
    //m.print();
    std::cout << std::endl;
    //m.mergeSort();
    auto start = std::chrono::high_resolution_clock::now();
    m1.bubbleSort();
    auto stop = std::chrono::high_resolution_clock::now();
    
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "buble sort time: " << (double)duration.count() / 1000000 << "s" << std::endl;
    
    start = std::chrono::high_resolution_clock::now();
    m2.mergeSort();
    stop = std::chrono::high_resolution_clock::now();
    
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "merge sort time: " << (double)duration.count() / 1000000 << "s" << std::endl;
    
    
    start = std::chrono::high_resolution_clock::now();
    m3.bubbleSortParallel();
    stop = std::chrono::high_resolution_clock::now();
    
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "buble sort parallel time: " << (double)duration.count() / 1000000 << "s" << std::endl;
    
    
    start = std::chrono::high_resolution_clock::now();
    m4.mergeSortParallel();
    stop = std::chrono::high_resolution_clock::now();
    
    duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "merge sort parallel time: " << (double)duration.count() / 1000000 << "s" << std::endl;
    
    //m.print();
    return 0;
}
