#include "command.h"

void Command1(const std::string &algorithm, const std::string &given_input, const std::string &output_param)
{
    int countComparisons = 0;

    std::ifstream input(given_input);
    std::vector<int> arr;
    int val;
    while (input >> val)
    {
        arr.push_back(val);
    }

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm))(arr, countComparisons);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime = end - start;

    OUTPUT_PARAM outputParam = outputParamMap.at(output_param);

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithm << '\n';
    std::cout << "Input file: " << given_input << '\n';
    std::cout << "Input size: " << arr.size() << '\n';
    std::cout << "---------------------------\n";
    if (outputParam == TIME || outputParam == BOTH)
        std::cout << "Running time: " << runTime.count() << '\n';
    if (outputParam == COMPARISIONS || outputParam == BOTH)
        std::cout << "Comparisons: " << countComparisons << '\n';
}