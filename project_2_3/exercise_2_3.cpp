#include <iostream>
#include <vector>
#include "BaseConv.hpp"

std::vector<int> readInVector(std::string s) {
    int prev_location = 0;
    int next_location = 0;
    std::vector<int> result;
    while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
        result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
        next_location++;
        prev_location = next_location;
    }
    result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
    return result;
}

int main() {
  std::string inStatsStr;
  std::cin >> inStatsStr;
  std::vector<int> inStats;
  inStats = readInVector(inStatsStr);
  BaseConv conv(inStats);

  std::string outType;
  std::cin >> outType;
  std::string input;
  std::cin >> input;

  std::string inType = "d";
  if (input.rfind("b", 0) == 0) { // find backwards, starting at index 0, rfind rets index of substr if found, -1 if not
    inType = "b";
    input.erase(0, 1);
  } else if (input.rfind("0x", 0) == 0) {
    inType = "h";
    input.erase(0, 2);
  }

  std::cout << "input: " << input << std::endl;
  std::cout << "output type: " << outType << std::endl;

  std::cout << "result: ";
  if (inType == "b") {
    if (outType == "d") {
      std::cout << conv.binToDec(input) << std::endl;
    } else if (outType == "h") {
      std::cout << conv.binToHex(input) << std::endl;
    }
  } else if (inType == "h") {
    if (outType == "d") {
      std::cout << conv.hexToDec(input) << std::endl;
    } else if (outType == "b") {
      std::cout << conv.hexToBin(input) << std::endl;
    }
  } else if (inType == "d") {
    if (outType == "h") {
      std::cout << conv.decToHex(input) << std::endl;
    } else if (outType == "b") {
      std::cout << conv.decToBin(input) << std::endl;
    }
  }

  conv.addIOStats(inType, outType);

  // done in destructor as requested
  // conv.printStats();
}
