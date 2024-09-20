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
    
    Matrix m = Matrix(8, 30);
    m.print();
    std::cout << std::endl;
    m.mergeSort();
    m.print();
    
   // int array[4] = { 6, 4, 3, 5 };
    
//    mergeSort(array, 0, 3);
    
    return 0;
}
