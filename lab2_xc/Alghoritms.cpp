//
//  Alghoritms.cpp
//  lab2_xc
//
//  Created by Andrii Staryk on 20.09.2024.
//

#include "Alghoritms.hpp"
#include <iostream>

void print(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << "\t";
    }
 }

void bubbleSort(int* array, int size) {
    bool swapped;
    
    for (int i = 0; i < size - 1; ++i) {
        
        swapped = false;
        
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) { break; }
    }
}


void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary arrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray if any
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray if any
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Free temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

// Recursive function to implement merge sort
void mergeSort(int* array, int left, int right) {
    
    if (left < right) {
        int mid = left + (right - left) / 2; // Avoid overflow

        // Recursively sort the first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}
