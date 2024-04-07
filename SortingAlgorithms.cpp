//
// Created by Bedirhan Omaç on 7.04.2024.
//

#include "SortingAlgorithms.h"


void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int indexOfLargest(const int arr[], int size) {
    int indexSoFar = 0;
    for(int currentIndex = 1; currentIndex < size; currentIndex++) {
        if(arr[currentIndex] > arr[indexSoFar]) {
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar;
}

void partition(int arr[], int first, int last, int& pivotIndex, int& swaps, int& comparisons) {
    int pivot = arr[first];
    int lastS1 = first;
    int firstUnknown = first + 1;

    for(; firstUnknown <= last; firstUnknown++) {
        comparisons++;
        if(arr[firstUnknown] < pivot) {
            lastS1++;
            swap(arr[lastS1], arr[firstUnknown]);
            swaps += 3;
        }
    }

    swap(arr[first], arr[lastS1]);
    swaps += 3;
    pivotIndex = lastS1;
}

void insertionSort(int arr[], int size, int& swaps, int& comparisons) {
    for(int unsorted = 1; unsorted < size; unsorted++) {
        int nextItem = arr[unsorted];
        int loc = unsorted;
        for(; loc > 0 && arr[loc-1] > nextItem; loc--) {
            arr[loc] = arr[loc-1];
            swaps += 3;
            comparisons++;
        }
        arr[loc] = nextItem;
    }
}

void selectionSort(int arr[], int size, int& swaps, int& comparisons) {
    for(int last = size - 1; last >= 1; last--) {
        int largest = indexOfLargest(arr, last + 1);
        swap(arr[largest], arr[last]);
        swaps += 3;
        comparisons++;
    }
}

void bubbleSort(int arr[], int size, int& swaps, int& comparisons) {
    bool sorted = false;
    for(int pass = 1; pass < size && !sorted; pass++) {
        sorted = true;
        for(int index = 0; index < size - pass; index++) {
            int nextIndex = index + 1;
            if(arr[index] > arr[nextIndex]) {
                swap(arr[index], arr[nextIndex]);
                swaps += 3;
            }
            comparisons++;
        }
    }
}

void quickSort(int arr[], int first, int last, int& swaps, int& comparisons) {
    int pivotIndex;
    if(first < last) {
        partition(arr, first, last, pivotIndex, swaps, comparisons);
        quickSort(arr, first, pivotIndex - 1, swaps, comparisons);
        quickSort(arr, pivotIndex + 1, last, swaps, comparisons);
    }
}


