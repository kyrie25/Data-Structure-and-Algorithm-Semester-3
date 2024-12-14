#include "algorithm.h"

void selectionSort(std::vector<int> &arr, int &countComparison)
{
    int n = arr.size();
    countComparison=0;

    for (int i = 0;++countComparison && i < n - 1; ++i)
    {

      
        int min_idx = i;

      
        for (int j = i + 1; ++countComparison && j< n; ++j)
        {
            if (++countComparison && arr[j] < arr[min_idx])
            {

               
                min_idx = j;
            }
        }

        
        std::swap(arr[i], arr[min_idx]);
    }
}
