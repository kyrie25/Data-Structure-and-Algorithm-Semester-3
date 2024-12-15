#include "algorithm.h"

void merge(std::vector<int> &arr, int left, int mid, int right, int& countComparison) 
{
    int n = mid - left + 1;
    int m = right - mid;

    std::vector<int> b(n), c(m);

    for (int i = 0; ++countComparison && i < n; i++) 
    {
        b[i] = arr[left + i]; 
    }

    for (int i = 0; ++countComparison && i < m; i++) 
    {
        c[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (++countComparison && i < n && ++countComparison && j < m) 
    {
        if (++countComparison && b[i] < c[j]) 
        {
            arr[k++] = b[i++];
        } 
        else 
        {
            arr[k++] = c[j++];
        }
    }

    while (++countComparison && i < n) 
    {
        arr[k++] = b[i++];
    }

    while (++countComparison && j < m) 
    {
        countComparison++; 
        arr[k++] = c[j++];
    }
}

void mergeSortRecur(std::vector<int>& arr, int left, int right, int& countComparison) 
{
    if (++countComparison && left < right) 
    { 
        int mid = (left + right) / 2;

        mergeSortRecur(arr, left, mid, countComparison);
        mergeSortRecur(arr, mid + 1, right, countComparison);

        merge(arr, left, mid, right, countComparison);
    }
}

void mergeSort(std::vector<int>& arr, int& countComparison) 
{
    int left = 0;
    int right = arr.size() - 1;

    mergeSortRecur(arr, left, right, countComparison);
}