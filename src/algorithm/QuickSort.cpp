#include "algorithm.h"

// choose pivot as middle element
int partition(std::vector<int> &arr, int left, int right, int &countComparisions)
{
    int pivot_value = arr[left + (right - left) / 2];
    int i = left, j = right;
    while (++countComparisions && i <= j)
    {
        while (++countComparisions && arr[i] < pivot_value)
        {
            i++;
        }

        while (++countComparisions && arr[j] > pivot_value)
        {
            j--;
        }

        if (++countComparisions && i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSortRecursive(std::vector<int> &arr, int left, int right, int &countComparisions)
{
    if (++countComparisions && left >= right)
    {
        return;
    }

    int pivot = partition(arr, left, right, countComparisions);

    quickSortRecursive(arr, left, pivot - 1, countComparisions);
    quickSortRecursive(arr, pivot, right, countComparisions);
}

void quickSort(std::vector<int> &arr, int &countComparisions)
{
    quickSortRecursive(arr, 0, arr.size() - 1, countComparisions);
}