#include <iostream>
#include <vector>

#pragma once

class BaseConv {
  std::vector<int> stats;

public:
  BaseConv(std::vector<int> const&);
  ~BaseConv();

  int charToInt(char c);
  char intToChar(int i);

  int binToDec(std::string bin);
  int hexToDec(std::string hex);

  std::string decToHex(std::string dec);
  std::string binToHex(std::string bin);

  std::string hexToBin(std::string hex);
  std::string decToBin(std::string dec);

  void addIOStats(std::string inType, std::string outType);
  void printStats();
};
