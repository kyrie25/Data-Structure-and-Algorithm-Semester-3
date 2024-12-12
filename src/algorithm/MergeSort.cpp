#include "algorithm.h"

void merge(std::vector<int> &arr, int left, int mid, int right, int& countComparison) {
    int n = mid - left + 1;
    int m = right - mid;

    std::vector<int> b(n), c(m);

    for (int i = 0; i < n; i++) {
        b[i] = arr[left + i];
        countComparison++; 
    }

    for (int i = 0; i < m; i++) {
        c[i] = arr[mid + i + 1];
        countComparison++; 
    }

    int i = 0, j = 0, k = left;

    while (i < n && j < m) {
        countComparison += 3; 
        if (b[i] < c[j]) {
            arr[k++] = b[i++];
        } else {
            arr[k++] = c[j++];
        }
    }

    while (i < n) {
        countComparison++; 
        arr[k++] = b[i++];
    }

    while (j < m) {
        countComparison++; 
        arr[k++] = c[j++];
    }
}

void mergeSortRecur(std::vector<int>& arr, int left, int right, int& countComparison) {
    if (left < right) {
        countComparison++; 
        int mid = (left + right) / 2;

        mergeSortRecur(arr, left, mid, countComparison);
        mergeSortRecur(arr, mid + 1, right, countComparison);

        merge(arr, left, mid, right, countComparison);
    }
}

void mergeSort(std::vector<int>& arr, int& countComparison) {
    int left = 0;
    int right = arr.size() - 1;

    mergeSortRecur(arr, left, right, countComparison);
}