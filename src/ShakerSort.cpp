#include "algorithm.h"

void ShakerSort(std::vector<int> &arr)
{
    int n = arr.size();

    int Left = 0;
    int Right = n - 1;
    int k = 0;
    int i;
    while (Left < Right)
    {
        for (i = Left; i < Right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                k = i;
            }
         }
        Right = k;
        for (i = Right; i > Left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                std::swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}