#include "command.h"

void Command1(const std::string &algorithm, const std::string &given_input, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

    std::ifstream input(given_input);
    std::vector<int> arr;
    int arrSize;
    input >> arrSize;
    int val;
    while (input >> val)
    {
        arr.push_back(val);
    }

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm))(arr, countComparisons);
    auto end = std::chrono::high_resolution_clock::now();

    std::ofstream outFile;
    outFile.open("output.txt");
    outFile << arrSize << '\n';
    for (int x : arr)
    {
        outFile << x << ' ';
    }
    outFile.close();

    std::chrono::duration<double> runTime = (end - start) * 1000.0;

    OUTPUT_PARAM outputParam = outputParamMap.at(output_param);

    std::string algorithmName = algorithmNameMap.at(algorithmMap.at(algorithm));

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithmName << '\n';
    std::cout << "Input file: " << given_input << '\n';
    std::cout << "Input size: " << arrSize << '\n';
    std::cout << "---------------------------\n";
    if (outputParam == TIME || outputParam == BOTH)
        std::cout << std::setprecision(6) << std::fixed << runTime.count() << " ms" << '\n';
    if (outputParam == COMPARISIONS || outputParam == BOTH)
        std::cout << "Comparisons: " << std::to_string(countComparisons) << '\n';
}