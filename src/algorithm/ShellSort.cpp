#include "algorithm.h"

void shellSort(std::vector<int> &arr, int &countComparison)
{
    int n = arr.size();

    for (int gap = n / 2; ++countComparison && gap > 0; gap /= 2)
    {
        for (int i = gap; ++countComparison && i < n; i++)
        {
            int temp = arr[i];
            
            int j;
            for (j = i; ++countComparison && j >= gap && ++countComparison && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

