#include "algorithm.h"

// choose pivot as middle element
int partition(std::vector<int> &arr, int left, int right, unsigned long long &countComparison)
{
    int pivot_value = arr[left + (right - left) / 2];
    int i = left, j = right;
    while (++countComparison && i <= j)
    {
        while (++countComparison && arr[i] < pivot_value)
        {
            i++;
        }

        while (++countComparison && arr[j] > pivot_value)
        {
            j--;
        }

        if (++countComparison && i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSortRecursive(std::vector<int> &arr, int left, int right, unsigned long long &countComparison)
{
    if (++countComparison && left >= right)
    {
        return;
    }

    int pivot = partition(arr, left, right, countComparison);

    quickSortRecursive(arr, left, pivot - 1, countComparison);
    quickSortRecursive(arr, pivot, right, countComparison);
}

void quickSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    quickSortRecursive(arr, 0, arr.size() - 1, countComparison);
}