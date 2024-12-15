#include "utils.h"

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(std::vector<int> &arr)
{
	int n = arr.size();
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(arr[r1], arr[r2]);
	}
}

void GenerateData(std::vector<int> &arr, int dataType)
{
	switch (dataType)
	{
	case 0: // ngẫu nhiên
		GenerateRandomData(arr);
		break;
	case 1: // có thứ tự
		GenerateSortedData(arr);
		break;
	case 2: // có thứ tự ngược
		GenerateReverseData(arr);
		break;
	case 3: // gần như có thứ tự
		GenerateNearlySortedData(arr);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}