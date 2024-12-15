#include "algorithm.h"
#include <cmath>

void flashSort(std::vector<int> &arr, unsigned long long &countComparison)
{
    int n = arr.size();
    int min = arr[0], max = arr[0];

    for (int i = 0; ++countComparison && i < n; i++)
    {
        if (++countComparison && min > arr[i])
            min = arr[i];
        if (++countComparison && max < arr[i])
            max = arr[i];
    }

    if (++countComparison && min == max)
        return;

    int m = 0.45 * n;
    std::vector<int> l(m, 0);

    for (int i = 0; ++countComparison && i < n; i++)
    {
        int k = floor((m - 1) * (arr[i] - min) * 1.0 / (max - min));
        l[k]++;
    }

    for (int i = 0; ++countComparison && i < m; i++)
    {
        l[i] += l[i - 1];
    }

    int move = 0;
    int flash = 0;
    int hold = 0;
    int k = 0;
    int i = 0;

    while (++countComparison && move < n - 1)
    {
        while (++countComparison && i > l[k] - 1)
        {
            i++;
            k = floor((m - 1) * (arr[i] - min) / (max - min));
        }

        flash = arr[i];
        if (++countComparison && k < 0)
            break;

        while (++countComparison && i != l[k])
        {
            k = floor((m - 1) * (flash - min) / (max - min));
            --l[k];
            hold = arr[l[k]];
            arr[l[k]] = flash;
            flash = hold;
            move++;
        }
    }

    insertionSort(arr, countComparison);
}