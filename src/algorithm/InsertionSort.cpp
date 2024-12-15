#include "algorithm.h"

void insertionSort(std::vector<int> &arr, int &countComparison)
{
    int n = arr.size();
    for (int i = 1; ++countComparison && i < n; ++i) 
    {
        int key = arr[i];
        int j = i - 1;

        while (++countComparison && j >= 0 && ++countComparison &&  arr[j] > key) 
        {
          
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}

