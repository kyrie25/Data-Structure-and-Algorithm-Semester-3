#include "command.h"

void Command2(const std::string &algorithm, const int &input_size,
              const std::string &input_order, const std::string &output_param)
{
    double runTime = 0;
    int countComparisons = 0;

    DATA_TYPE dataType = dataTypeMap.at(input_order);

    std::vector<int> arr;
    arr.resize(input_size);
    GenerateData(arr, dataType);

    // write generated data to input.txt
    std::ofstream outFile;
    outFile.open("input.txt");
    outFile << arr.size() << ' ';
    for (int x : arr)
    {
        outFile << x << ' ';
    }
    outFile.close();

    // measure running time and comparisons
    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithmMap.at(algorithm))(arr, countComparisons);
    auto end = std::chrono::high_resolution_clock::now();

    // write sorted data to output.txt
    outFile.open("output.txt");
    outFile << arr.size() << ' ';
    for (int x : arr)
    {
        outFile << x << ' ';
    }
    outFile.close();
    OUTPUT_PARAM outputParam = outputParamMap.at(output_param);

    std::cout << "ALGORITHM MODE\n"
              << "Algorithm: " << algorithm << '\n'
              << "Input size: " << input_size << '\n'
              << "Input order: " << input_order << '\n'
              << "---------------------------\n"

              << "Running time (if required): "
              << ((outputParam == TIME || outputParam == BOTH) ? std::to_string((end - start).count()) : "") << '\n'

              << "Comparisions (if required): "
              << ((outputParam == COMPARISIONS || outputParam == BOTH) ? std::to_string(countComparisons) : "") << '\n';
}