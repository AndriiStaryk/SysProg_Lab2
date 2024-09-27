//
//  main.cpp
//  lab2_xc
//
//  Created by Andrii Staryk on 20.09.2024.
//

#include "Matrix.hpp"
#include "Alghoritms.hpp"
#include <iostream>	
#include <chrono>

int main(int argc, const char * argv[]) {
    
    Matrix m = Matrix(1000, 4000, 25);
 
    std::cout << "Hi there. The matrix is generated :)" << std::endl;
    

    auto start = std::chrono::high_resolution_clock::now();
    m.bubbleSort();
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "sort time: " << (double)duration.count() / 1000000 << "s" << std::endl;
    

    return 0;
}
