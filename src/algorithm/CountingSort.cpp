#include "algorithm.h"

void countingSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();
    int max = arr[0];

    for (int i = 1; ++countComparison && i < n; i++)
    {
        if (++countComparison && arr[i] > max)
            max = arr[i];
    }

    std::vector<int> count(max + 1, 0);
    for (int i = 0; ++countComparison && i < n; i++)
        count[arr[i]]++;
    for (int i = 1; ++countComparison && i <= max; i++)
        count[i] += count[i - 1];

    std::vector<int> res(n);
    for (int i = n - 1; ++countComparison && i >= 0; i--)
    {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = std::move(res);
}