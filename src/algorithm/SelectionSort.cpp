#include "algorithm.h"

void selectionSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();

    for (int i = 0; ++countComparison && i < n - 1; ++i)
    {
        int min_idx = i;

        for (int j = i + 1; ++countComparison && j < n; ++j)
        {
            if (++countComparison && arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        std::swap(arr[i], arr[min_idx]);
    }
}
