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
void GenerateRandomData(vector<int> &arr)
{
	int n = arr.size();
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		arr.push_back(rand()%n);
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i);
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(vector<int> &arr)
{
	int n = arr.size();
	for (int i = n; i > 0; i--)
	{
		arr.push_back(i);
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		arr.push_back(i);
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(arr[r1], arr[r2]);
	}
}

void GenerateData(vector<int> &arr, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(arr);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(arr);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(arr);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(arr);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}