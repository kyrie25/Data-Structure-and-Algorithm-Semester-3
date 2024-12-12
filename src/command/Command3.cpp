#include "command.h"
#include "algorithm/algorithm.h"
#include <chrono>
#include <fstream>
#include <vector>

void Command3(const std::string &algorithm, const int &input_size, const std::string &output_param)
{
    int countComparisons = 0;

    std::vector<int> arr0;
    arr0.resize(input_size);
    GenerateData(arr0, 0);

    std::vector<int> arr1;
    arr1.resize(input_size);
    GenerateData(arr1, 1);

    std::vector<int> arr2;
    arr2.resize(input_size);
    GenerateData(arr2, 2);

    std::vector<int> arr3;
    arr3.resize(input_size);
    GenerateData(arr3, 3);

    std::vector<std::vector<int>> arr;

    arr.push_back(arr0);
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);

    std::ofstream output1("input1.txt");
    if (output1.is_open())
    {
        output1 << input_size << '\n';
        for(int i = 0; i < input_size; i++)
        {
            output1 << arr0[i] << ' ';
        }
        output1.close();
    }
    else
    {
        std::cerr << "Unable to open file input1.txt\n";
        exit(1);
    }

    std::ofstream output2("input2.txt");
    if (output2.is_open())
    {
        output2 << input_size << '\n';
        for(int i = 0; i < input_size; i++)
        {
            output2 << arr1[i] << ' ';
        }
        output2.close();
    }
    else
    {
        std::cerr << "Unable to open file input2.txt\n";
        exit(1);
    }

    std::ofstream output3("input3.txt");
    if (output3.is_open())
    {
        output3 << input_size << '\n';
        for(int i = 0; i < input_size; i++)
        {
            output3 << arr2[i] << ' ';
        }
        output3.close();
    }
    else
    {
        std::cerr << "Unable to open file input3.txt\n";
        exit(1);
    }

    std::ofstream output4("input4.txt");
    if (output4.is_open())
    {
        output4 << input_size << '\n';
        for(int i = 0; i < input_size; i++)
        {
            output4 << arr3[i] << ' ';
        }
        output4.close();
    }
    else
    {
        std::cerr << "Unable to open file input4.txt\n";
        exit(1);
    }

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithm << '\n';
    std::cout << "Input size: " << input_size << '\n';

    for(int i = 0; i < 4; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        algorithmFunctionMap.at(algorithmMap.at(algorithm))(arr[i], countComparisons);
        auto end = std::chrono::high_resolution_clock::now();

        OUTPUT_PARAM outputParam = outputParamMap.at(output_param);

        if (i == 0)
        {
            std::cout << "Input order: Randomize\n";
        }
        else if (i == 1)
        {
            std::cout << "Input order: Sorted\n";
        }
        else if (i == 2)
        {
            std::cout << "Input order: Reversed\n";
        }
        else
        {
            std::cout << "Input order: Nearly Sorted\n";
        }
    
        std::cout << "-------------------------\n";
        std::cout << "Running time (if required): ";
        std::cout << ((outputParam == TIME || outputParam == BOTH) ? std::to_string((end - start).count() * 1000.0) : "") << '\n';
        std::cout << "Comparisions (if required): ";
        std::cout << ((outputParam == COMPARISIONS || outputParam == BOTH) ? std::to_string(countComparisons) : "") << '\n';
    }
}