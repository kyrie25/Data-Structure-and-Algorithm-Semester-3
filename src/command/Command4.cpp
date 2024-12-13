#include "command.h"
#include "../algorithm/algorithm.h"
#include "../utils/utils.h"
#include <chrono>
#include <fstream>
#include <vector>

void Command4(std::string algorithm1, std::string algorithm2, std::string inputFile) {

    std::ifstream input(inputFile);
    std::vector<int> arr;
    int val;
    while (input >> val) {
        arr.push_back(val);
    }
    
    std::vector<int> arr1 = arr;
    std::vector<int> arr2 = arr;
    int countComparison1 = 0;
    int countComparison2 = 0;

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm1))(arr1, countComparison1);
    auto end = std::chrono::high_resolution_clock::now();

    auto runTime1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm2))(arr2, countComparison2);
    end = std::chrono::high_resolution_clock::now();

    auto runTime2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << '\n';
    std::cout << "Input file: " << inputFile << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Running time: " << runTime1.count() << " ms | " << runTime2.count() << " ms" << '\n';
    std::cout << "Comparisons: " << countComparison1 << " | " << countComparison2 << '\n';

}