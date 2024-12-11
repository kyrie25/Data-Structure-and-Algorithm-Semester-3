#include "header.h"

void merge(std::vector<int>& a, int left, int mid, int right) {
    int n = mid - left + 1;
    int m = right - mid;

    std::vector<int> b(n), c(m);
    
    for (int i = 0; i < n; i++) 
        b[i] = a[left + i];
    for (int i = 0; i < m; i++)
        c[i] = a[mid + i + 1];

    int i = 0, j = 0, k = left;

    while (i < n && j < m) {
        if (b[i] < c[j])
            a[k++] = b[i++];
        else
            a[k++] = c[j++];
    }

    while (i < n) 
        a[k++] = b[i++];

    while (j < m)
        a[k++] = c[j++]; 
}

void mergeSort(std::vector<int>& a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}
