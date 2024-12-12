#include "algorithm.h"
#include <vector>

void countSort(std::vector<int> &arr, int n, int pos, int &countComparison) {
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) 
    {
        count[(arr[i] / pos) % 10]++;
        countComparison++; 
    }

    for (int i = 1; i < 10; i++) 
    {
        count[i] += count[i - 1];
        countComparison++; 
    }

    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) 
    {
        ans[--count[(arr[i] / pos) % 10]] = arr[i];
        countComparison++; 
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = ans[i];
        countComparison++; 
    }
}

void radixSort(std::vector<int> &arr, int &countComparison) {
    int n = arr.size();
    int k = arr[0];
    for (int i = 1; i < n; i++) 
    {
        k = std::max(k, arr[i]);
        countComparison++; 
    }

    for (int pos = 1; (k / pos) > 0; pos *= 10) 
    {
        countComparison++; 
        countSort(arr, n, pos, countComparison);
    }
}