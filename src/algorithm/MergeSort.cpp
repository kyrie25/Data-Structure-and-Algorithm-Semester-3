#include "algorithm.h"

void merge(std::vector<int> &arr, int left, int mid, int right) 
{
    int n = mid - left + 1;
    int m = right - mid;

    std::vector<int> b(n), c(m);
    
    for (int i = 0; i < n; i++) 
        b[i] = arr[left + i];
    for (int i = 0; i < m; i++)
        c[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = left;

    while (i < n && j < m) 
    {
        if (b[i] < c[j])
            arr[k++] = b[i++];
        else
            arr[k++] = c[j++];
    }

    while (i < n) 
        arr[k++] = b[i++];

    while (j < m)
        arr[k++] = c[j++]; 
}

void mergeSortRecur(std::vector<int> &arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = (left + right) / 2;

        mergeSortRecur(arr, left, mid);
        mergeSortRecur(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeSort(std::vector<int> &arr)
{
    int left = 0;
    int right = arr.size();

    mergeSortRecur(arr, left, right);
}
