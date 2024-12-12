#include "algorithm.h"

void insertionSort(std::vector<int> &arr, int &countComparison)
{
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            countComparison += 2;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        countComparison++;
        arr[j + 1] = key;
    }
}

