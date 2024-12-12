#include "algorithm.h"

void shakerSort(std::vector<int> &arr)
{
    int n = arr.size();

    int l = 0;
    int r = n - 1;
    int k = 0;
    int i;

    while (l < r)
    {
        for (i = l; i < r; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                k = i;
            }
         }
        r = k;
        for (i = r; i > l; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        l = k;
    }
}