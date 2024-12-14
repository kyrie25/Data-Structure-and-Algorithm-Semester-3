#include "algorithm.h"

void insertionSort(std::vector<int> &arr, int &countComparison)
{
    int n = arr.size();
    countComparison=0;
    for (int i = 1; ++countComparison && i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        
        while (  j >= 0 && arr[j] > key) {
           countComparison+=2
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        countComparison++;
        arr[j + 1] = key;
    }
}

