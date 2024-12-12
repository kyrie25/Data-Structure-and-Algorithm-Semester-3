#include "algorithm.h"

void countSort(std::vector<int>& arr, int n, int pos) {
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int n = arr.size();
    int k = arr[0];
    for (int i = 0; i < n; i++)
        k = std::max(k, arr[i]);

    for (int pos = 1; (k / pos) > 0; pos *= 10) {
        countSort(arr, n, pos);
    }
}