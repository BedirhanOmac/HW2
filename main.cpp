#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include "SortingAlgorithms.h"

using namespace std;

int *generate_random_array(int size) {
    int* rand_arr = new int[size];
    int i;
    for(i = 0; i < size; i++) {
        rand_arr[i] = rand() % 5000;
    }
    return rand_arr;
}

int *generate_almost_sorted_array(int size) {
    srand((unsigned int)time(NULL));
    int *random_array = generate_random_array(size);

    int swap_count = size * 0.03;
    for (int i = 0; i < swap_count; i++) {
        int first_index = rand() % size;
        int second_index = size - first_index;
        int temp = random_array[first_index];
        random_array[first_index] = random_array[second_index];
        random_array[second_index] = temp;
    }
    return random_array;
}


int main() {
    const int num_trucks = 10;
    const int truck_sizes[] = { 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 };

    srand(time(nullptr));

    // Test Insertion Sort
    cout << "Results for Insertion Sort:" << endl;
    for(int i = 0; i < num_trucks; i++) {
        int truck_size = truck_sizes[i];
        double avgTime = 0;
        for(int j = 0; j < 5; j++) {
            int* tree_heights = generate_almost_sorted_array(truck_size);
            int swaps = 0;
            int comparisons = 0;

            insertionSort(tree_heights, truck_size, swaps, comparisons);

            double totalTime = (swaps * 15 + comparisons);
            avgTime += totalTime;

            delete[] tree_heights;
        }
        avgTime /= 5;
        cout << "Truck size: " << truck_size << ", Time: " << avgTime << " seconds" << endl;
    }
    cout << endl;

    // Test Selection Sort
    cout << "Results for Selection Sort:" << endl;
    for(int i = 0; i < num_trucks; i++) {
        int truck_size = truck_sizes[i];
        double avgTime = 0;
        for(int j = 0; j < 5; j++) {
            int* tree_heights = generate_almost_sorted_array(truck_size);
            int swaps = 0;
            int comparisons = 0;

            selectionSort(tree_heights, truck_size, swaps, comparisons);

            double totalTime = (swaps * 15 + comparisons);
            avgTime += totalTime;

            delete[] tree_heights;
        }
        avgTime /= 5;
        cout << "Truck size: " << truck_size << ", Time: " << avgTime << " seconds" << endl;
    }
    cout << endl;

    // Test Bubble Sort
    cout << "Results for Bubble Sort:" << endl;
    for(int i = 0; i < num_trucks; i++) {
        int truck_size = truck_sizes[i];
        double avgTime = 0;
        for(int j = 0; j < 5; j++) {
            int* tree_heights = generate_almost_sorted_array(truck_size);
            int swaps = 0;
            int comparisons = 0;

            bubbleSort(tree_heights, truck_size, swaps, comparisons);

            double totalTime = (swaps * 15 + comparisons);
            avgTime += totalTime;

            delete[] tree_heights;
        }
        avgTime /= 5;
        cout << "Truck size: " << truck_size << ", Time: " << avgTime << " seconds" << endl;
    }
    cout << endl;

    // Test Quick Sort
    cout << "Results for Quick Sort:" << endl;
    for(int i = 0; i < num_trucks; i++) {
        int truck_size = truck_sizes[i];
        double avgTime = 0;
        for(int j = 0; j < 5; j++) {
            int* tree_heights = generate_almost_sorted_array(truck_size);
            int swaps = 0;
            int comparisons = 0;

            quickSort(tree_heights, 0, truck_size - 1, swaps, comparisons);

            double totalTime = (swaps * 15 + comparisons);
            avgTime += totalTime;

            delete[] tree_heights;
        }
        avgTime /= 5;
        cout << "Truck size: " << truck_size << ", Time: " << avgTime << " seconds" << endl;
    }

    return 0;
}

