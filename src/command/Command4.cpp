#include "command.h"
#include "algorithm/algorithm.h"
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

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm1))(arr1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime1 = end - start;

    start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm2))(arr2);
    end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime2 = end - start;

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << '\n';
    std::cout << "Input file: " << inputFile << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Running time: " << runTime1.count() << " | " << runTime2.count() << '\n';
    std::cout << "Comparisions: ";

}