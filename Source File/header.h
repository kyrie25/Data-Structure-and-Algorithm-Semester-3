#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <string>
#include <map>

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
    {"flash-sort", FLASH_SORT}};

const std::map<std::string, DATA_TYPE> dataTypeMap = {
    {"-rand", RANDOM},
    {"-nsorted", NEARLY_SORTED},
    {"-sorted", SORTED},
    {"-rev", REVERSE}};

const std::map<std::string, OUTPUT_PARAM> outputParamMap = {
    {"-time", TIME},
    {"-comp", COMPARISIONS},
    {"-both", BOTH}};

// bubble sort
void bubbleSort(std::vector<int> &a, int n);

// quick sort
int partition(std::vector<int> &a, int low, int high);
void quickSort(std::vector<int> &a, int low, int high);

// merge sort
void merge(std::vector<int> &a, int left, int mid, int right);
void mergeSort(std::vector<int> &a, int left, int right);

// heap sort
void heapify(std::vector<int> &a, int n, int i);
void heapSort(std::vector<int> &a, int n);

#endif // !HEADER_H