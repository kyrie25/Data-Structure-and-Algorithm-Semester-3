#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

enum SORT_ALGORITHMS
{
    SELECTION_SORT,
    INSERTION_SORT,
    BUBBLE_SORT,
    SHAKER_SORT,
    SHELL_SORT,
    HEAP_SORT,
    MERGE_SORT,
    QUICK_SORT,
    COUNTING_SORT,
    RADIX_SORT,
    FLASH_SORT
};

enum DATA_TYPE
{
    RANDOM,
    NEARLY_SORTED,
    SORTED,
    REVERSE
};

enum OUTPUT_PARAM
{
    TIME,
    COMPARISIONS,
    BOTH
};

const std::map<std::string, SORT_ALGORITHMS> algorithmMap = {
    {"selection-sort", SELECTION_SORT},
    {"insertion-sort", INSERTION_SORT},
    {"bubble-sort", BUBBLE_SORT},
    {"shaker-sort", SHAKER_SORT},
    {"shell-sort", SHELL_SORT},
    {"heap-sort", HEAP_SORT},
    {"merge-sort", MERGE_SORT},
    {"quick-sort", QUICK_SORT},
    {"counting-sort", COUNTING_SORT},
    {"radix-sort", RADIX_SORT},
    {"flash-sort", FLASH_SORT}
};

const std::map<std::string, DATA_TYPE> dataTypeMap = {
    {"-rand", RANDOM},
    {"-nsorted", NEARLY_SORTED},
    {"-sorted", SORTED},
    {"-rev", REVERSE}
};

const std::map<std::string, OUTPUT_PARAM> outputParamMap = {
    {"-time", TIME},
    {"-comp", COMPARISIONS},
    {"-both", BOTH}
};

void mergeSort(std::vector<int> &arr);
void countingSort(std::vector<int> &arr);
void shakerSort(std::vector<int> &arr);
void shellSort(std::vector<int> &arr);
void heapSort(std::vector<int> &arr);
void flashSort(std::vector<int> &arr);
void quickSort(std::vector<int> &arr);
void bubbleSort(std::vector<int> &arr);
void insertionSort(std::vector<int> &arr);
void radixSort(std::vector<int> &arr);
void selectionSort(std::vector<int> &arr);

const std::map<SORT_ALGORITHMS, std::function<void(std::vector<int> &)>> algorithmFunctionMap = {
    {SELECTION_SORT, selectionSort},
    {INSERTION_SORT, insertionSort},
    {BUBBLE_SORT, bubbleSort},
    {SHAKER_SORT, shakerSort},
    {SHELL_SORT, shellSort},
    {HEAP_SORT, heapSort},
    {MERGE_SORT, mergeSort},
    {QUICK_SORT, quickSort},
    {COUNTING_SORT, countingSort},
    {RADIX_SORT, radixSort},
    {FLASH_SORT, flashSort}
};

const std::map<SORT_ALGORITHMS, std::string> algorithmNameMap = {
    {SELECTION_SORT, "Selection Sort"},
    {INSERTION_SORT, "Insertion Sort"},
    {BUBBLE_SORT, "Bubble Sort"},
    {SHAKER_SORT, "Shaker Sort"},
    {SHELL_SORT, "Shell Sort"},
    {HEAP_SORT, "Heap Sort"},
    {MERGE_SORT, "Merge Sort"},
    {QUICK_SORT, "Quick Sort"},
    {COUNTING_SORT, "Counting Sort"},
    {RADIX_SORT, "Radix Sort"},
    {FLASH_SORT, "Flash Sort"}
};

#endif // !HEADER_H
