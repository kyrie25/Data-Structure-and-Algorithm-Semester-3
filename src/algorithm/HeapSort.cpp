#include "algorithm.h"

void heapify(std::vector<int>& arr, int n, int i, int &countComparison)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (++countComparison && left < n && ++countComparison && arr[largest] < arr[left])
        largest = left;

    if (++countComparison && right < n && ++countComparison && arr[largest] < arr[right])
        largest = right;

    if (++countComparison && largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, countComparison); // Đệ quy
    }
}

void heapSort(std::vector<int> &arr, int &countComparison)
{
    int n = arr.size();

    for (int i = n / 2 - 1; ++countComparison && i >= 0; i--)
    {
        heapify(arr, n, i, countComparison);
    }

    for (int i = n - 1; ++countComparison && i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, countComparison);
    }
}
