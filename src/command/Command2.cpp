#include "command.h"

void Command2(const std::string &algorithm, const int &input_size,
              const std::string &input_order, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

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

    auto runTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // write sorted data to output.txt
    outFile.open("output.txt");
    outFile << arr.size() << ' ';
    for (int x : arr)
    {
        outFile << x << ' ';
    }
    outFile.close();
    OUTPUT_PARAM outputParam = outputParamMap.at(output_param);

    std::string algorithmName = algorithmNameMap.at(algorithmMap.at(algorithm));
    std::string dataTypeName = dataTypeNameMap.at(dataType);

    std::cout << "ALGORITHM MODE\n"
              << "Algorithm: " << algorithmName << '\n'
              << "Input size: " << input_size << '\n'
              << "Input order: " << dataTypeName << '\n'
              << "---------------------------\n";

    std::cout << "Running time (if required): ";
    if (outputParam == TIME || outputParam == BOTH)
    {
        std::cout << std::to_string(runTime.count()) << " ms" << '\n';
    }
    else
    {
        std::cout << " " << '\n';
    }

    std::cout << "Comparisions (if required): ";
    if (outputParam == COMPARISIONS || outputParam == BOTH)
    {
        std::cout << std::to_string(countComparisons) << '\n';
    }
    else
    {
        std::cout << " " << '\n';
    }
}