#include "algorithm.h"

void shakerSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();

    int l = 0;
    int r = n - 1;
    int k = 0;
    int i;

    while (++countComparison && l < r)
    {
        for (i = l; ++countComparison && i < r; i++)
        {
            if (++countComparison && arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        r = k;
        for (i = r; ++countComparison && i > l; i--)
        {
            if (++countComparison && arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        l = k;
    }
}