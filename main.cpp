#include <iostream>
#include <fstream>
#include "src/include.h"

// Command 1: [Execution file] -a [Algorithm]   [Given input] [Output parameter(s)]
// Command 2: [Execution file] -a [Algorithm]   [Input size]  [Input order]             [Output parameter(s)]
// Command 3: [Execution file] -a [Algorithm]   [Input size]  [Output parameter(s)]
// Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
// Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size]              [Input order]

bool isValidAlgorithm(const std::string &algorithm)
{
    SORT_ALGORITHMS sort_algorithm = algorithmMap.at(algorithm);
    return sort_algorithm != algorithmMap.end()->second;
}

bool isValidInputOrder(const std::string &input_order)
{
    DATA_TYPE data_type = dataTypeMap.at(input_order);
    return data_type != dataTypeMap.end()->second;
}

bool isValidGivenInput(const std::string &given_input)
{
    std::ifstream inFile;
    inFile.open(given_input);
    if (inFile.is_open())
    {
        inFile.close();
        return true;
    }
    return false;
}

bool isValidOutputParam(const std::string &output_parameter)
{
    OUTPUT_PARAM output_param = outputParamMap.at(output_parameter);
    return output_param != outputParamMap.end()->second;
}

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        std::cerr << "Invalid command.\n";
        return 1;
    }

    std::string mode = argv[1];

    // algorithm mode
    if (mode == "-a")
    {
        std::string algorithm = argv[2];

        if (!isValidAlgorithm(algorithm))
        {
            std::cerr << "Invalid command.\n";
            return 1;
        }

        if (!isdigit(argv[3][0]))
        {
            std::string given_input = argv[3];
            std::string output_parameter = argv[4];

            if (!isValidGivenInput(given_input) || !isValidOutputParam(output_parameter))
            {
                std::cerr << "Invalid command.\n";
                return 1;
            }

            // command 1
            Command1(algorithm, given_input, output_parameter);
        }
        else
        {
            int input_size = std::stoi(argv[3]);
            std::string output_parameter = "";
            std::string input_order = "";

            if (argc > 5)
            {
                input_order = argv[4];
                output_parameter = argv[5];

                if (!isValidInputOrder(input_order) || !isValidOutputParam(output_parameter))
                {
                    std::cerr << "Invalid command.\n";
                    return 1;
                }
            }
            else
            {
                output_parameter = argv[4];
                if (!isValidOutputParam(output_parameter))
                {
                    std::cerr << "Invalid command.\n";
                    return 1;
                }
            }

            if (!input_order.empty())
            {
                // command 2
                Command2(algorithm, input_size, input_order, output_parameter);
            }
            else
            {
                // command 3
                // Command3(algorithm, input_size, output_parameter);
            }
        }
    }
    // comparision mode
    else if (mode == "-c")
    {
        std::string algorithm1 = argv[2];
        std::string algorithm2 = argv[3];

        if (!isValidAlgorithm(algorithm1) || !isValidAlgorithm(algorithm2))
        {
            std::cerr << "Invalid command.\n";
            return 1;
        }

        int input_size = 0;
        std::string given_input = "";
        std::string input_order = "";

        if (!isdigit(argv[4][0]))
        {
            given_input = argv[4];
            if (!isValidGivenInput(given_input))
            {
                std::cerr << "Invalid command.\n";
                return 1;
            }
        }
        else
        {
            if (argc > 5)
            {
                input_size = std::stoi(argv[4]);
                input_order = argv[5];

                if (!isValidInputOrder(input_order))
                {
                    std::cerr << "Invalid command.\n";
                    return 1;
                }
            }
            else
            {
                std::cerr << "Invalid command.\n";
                return 1;
            }
        }

        if (input_size == 0)
        {
            // command 4
            // Command4(algorithm1, algorithm2, given_input);
        }
        else
        {
            // command 5
            // Command5(algorithm1, algorithm2, input_size, input_order);
        }
    }
    else
    {
        std::cerr << "Invalid command.\n";
        return 1;
    }

    std::cout << "Successfully.\n";
    return 0;
}