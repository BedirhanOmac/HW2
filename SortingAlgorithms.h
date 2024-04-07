//
// Created by Bedirhan Omaç on 7.04.2024.
//

#ifndef HW2_TEST_SORTINGALGORITHMS_H
#define HW2_TEST_SORTINGALGORITHMS_H


void insertionSort(int arr[], int size, int& swaps, int& comparisons);
void selectionSort(int arr[], int size, int& swaps, int& comparisons);
void bubbleSort(int arr[], int size, int& swaps, int& comparisons);
void quickSort(int arr[], int first, int last, int& swaps, int& comparisons);
int indexOfLargest(const int arr[], int size);
void partition(int arr[], int first, int last, int& pivotIndex, int& swaps, int& comparisons);



#endif //HW2_TEST_SORTINGALGORITHMS_H
