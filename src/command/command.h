#pragma once
#ifndef COMMAND_H
#define COMMAND_H

#include "../algorithm/algorithm.h"
#include "../utils/utils.h"
#include <chrono>

void Command2(const std::string &algorithm, const int &input_size,
              const std::string &input_order, const std::string &output_param);

void Command4(std::string algorithm1, std::string algorithm2, std::string inputFile);
void Command5(std::string algorithm1, std::string algorithm2, std::string inputFile, std::string inputOrder);

#endif // COMMAND_H