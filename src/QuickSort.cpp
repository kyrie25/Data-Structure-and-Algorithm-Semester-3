#include "algorithm.h"

// choose pivot as middle element
int partition(std::vector<int> &arr, int left, int right)
{
    int pivot_value = arr[left + (right - left) / 2];
    int i = left, j = right;
    while (i <= j)
    {
        while (arr[i] < pivot_value)
        {
            i++;
        }

        while (arr[j] > pivot_value)
        {
            j--;
        }

        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSortRecursive(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivot = partition(arr, left, right);

    quickSortRecursive(arr, left, pivot - 1);
    quickSortRecursive(arr, pivot, right);
}

void quickSort(std::vector<int> &arr)
{
    quickSortRecursive(arr, 0, arr.size() - 1);
}