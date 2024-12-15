#include "command.h"
#include "../algorithm/algorithm.h"
#include "../utils/utils.h"
#include <chrono>
#include <fstream>
#include <vector>

void Command4(std::string algorithm1, std::string algorithm2, std::string inputFile)
{

    std::ifstream input(inputFile);
    std::vector<int> arr;
    int val;
    while (input >> val)
    {
        arr.push_back(val);
    }

    std::vector<int> arr1 = arr;
    std::vector<int> arr2 = arr;
    unsigned long long countComparison1 = 0;
    unsigned long long countComparison2 = 0;

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm1))(arr1, countComparison1);
    auto end = std::chrono::high_resolution_clock::now();

    auto runTime1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm2))(arr2, countComparison2);
    end = std::chrono::high_resolution_clock::now();

    auto runTime2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::string algorithmName1 = algorithmNameMap.at(algorithmMap.at(algorithm1));
    std::string algorithmName2 = algorithmNameMap.at(algorithmMap.at(algorithm2));

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithmName1 << " | " << algorithmName2 << '\n';
    std::cout << "Input file: " << inputFile << '\n';
    std::cout << "Input size: " << arr.size() << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Running time: " << runTime1.count() << " ms | " << runTime2.count() << " ms" << '\n';
    std::cout << "Comparisons: " << countComparison1 << " | " << countComparison2 << '\n';
}