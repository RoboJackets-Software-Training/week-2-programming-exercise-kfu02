#include <iostream>
#include <vector>

#pragma once

std::vector<double> readInVector(std::string s);

void printVector(std::vector<double> vec);
void printVector(std::string vec_name, std::vector<double> vec);

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros);
