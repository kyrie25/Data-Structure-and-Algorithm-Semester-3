#pragma once

#include <vector>

//merge sort
void merge(std::vector<int>& a, int left, int mid, int right);
void mergeSort(std::vector<int>& a, int left, int right);

//heap sort
void heapify(std::vector<int>& a, int n, int i);
void heapSort(std::vector<int>& a, int n);