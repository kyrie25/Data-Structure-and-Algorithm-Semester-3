#include "algorithm.h"

void bubbleSort(std::vector<int> &arr, int &countComparisons)
{
    int n = arr.size() - 1;
    for (int i = 0; ++countComparisons && i < n; i++)
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