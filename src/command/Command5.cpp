#include "command.h"

void Command5(const std::string &algorithm1, const std::string &algorithm2, const int &input_size, const std::string &input_order)
{
    unsigned long long countComparisons1 = 0, countComparisons2 = 0;

    DATA_TYPE dataType = dataTypeMap.at(input_order);

    std::vector<int> arr1(input_size);
    std::vector<int> arr2(input_size);
    GenerateData(arr1, dataType);
    arr2 = arr1; //  dữ liệu hai mảng phải giống nhau

    auto start1 = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm1))(arr1, countComparisons1);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto runTime1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm2))(arr2, countComparisons2);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto runTime2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << '\n';
    std::cout << "Input size: " << input_size << '\n';
    std::cout << "Input order: " << input_order << '\n';
    std::cout << "---------------------------\n";
    std::cout << "Running time: " << runTime1.count() << " ms | " << runTime2.count() << " ms" << '\n';
    std::cout << "Comparisons: " << countComparisons1 << " | " << countComparisons2 << '\n';
}