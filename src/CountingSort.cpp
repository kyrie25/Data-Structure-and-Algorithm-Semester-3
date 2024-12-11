#include "algorithm.h"

void countingSort(std::vector<int>& arr)
{

    int n = arr.size();
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    std::vector<int> countArray(max + 1, 0);
    for (int i = 0; i < n; i++)
        countArray[arr[i]]++;
    for (int i = 1; i <= max; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    std::vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        res[countArray[arr[i]] - 1]
            = arr[i];

        countArray[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = res[i];
}