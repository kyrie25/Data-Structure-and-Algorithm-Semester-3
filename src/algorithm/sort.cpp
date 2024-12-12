#include "algorithm.h"

void runSortAlgorithm(SORT_ALGORITHMS algorithm, std::vector<int>& arr) {
    switch (algorithm) {
        case SELECTION_SORT:
            selectionSort(arr);
            break;
        case INSERTION_SORT:
            insertionSort(arr);
            break;
        case BUBBLE_SORT:
            bubbleSort(arr);
            break;
        case SHAKER_SORT:
            shakerSort(arr);
            break;
        case SHELL_SORT:
            shellSort(arr);
            break;
        case HEAP_SORT:
            heapSort(arr);
            break;
        case MERGE_SORT:
            mergeSort(arr);
            break;
        case QUICK_SORT:
            quickSort(arr);
            break;
        case COUNTING_SORT:
            countingSort(arr);
            break;
        case RADIX_SORT:
            radixSort(arr);
            break;
        case FLASH_SORT:
            flashSort(arr);
            break;
        default:
            break;
    }
}