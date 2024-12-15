#include "algorithm.h"

void bubbleSort(std::vector<int> &arr, unsigned long long &countComparisons)
{
    int n = arr.size();
    for (int i = 0; ++countComparisons && i < n - 1; i++)
    {
        for (int j = 0; ++countComparisons && j < n - i - 1; j++)
        {
            if (++countComparisons && arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}