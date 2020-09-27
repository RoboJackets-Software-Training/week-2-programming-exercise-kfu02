#include <iostream>
#include <vector>
#include "convolution.hpp"

std::vector<double> readInVector(std::string s) {
    int prev_location = 0;
    int next_location = 0;
    std::vector<double> result;
    while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
        //std::cout << "prev_location: " << prev_location << std::endl;
        //std::cout << "next_location: " << next_location << std::endl;
        // substr [,]
        //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
        result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
        next_location++;
        prev_location = next_location;
    }
    result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
    return result;
}

void printVector(std::vector<double> vec) {
    std::cout << "{";
    for (int i=0; i<vec.size()-1; i++) {
    std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size()-1] << "}" << std::endl;
}

void printVector(std::string vec_name, std::vector<double> vec) {
  std::cout << vec_name << ": ";
  printVector(vec);
}

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
    std::vector<double> y;

    int shift = w.size()/2;
    for (int i=0; i<x.size(); i++) {
        double sum_at_pos = 0;
        for (int k=0; k<w.size(); k++) { // k = kernel_indx
            int input_indx = i+k-shift;
            double input_val =
            (input_indx>=0 && input_indx<x.size())
                ? x[input_indx]         // if index in bounds, set to val at index
                : (pack_with_zeros      // else, if pack_with_zeros
                    ? 0.0               // set val to 0
                    : (input_indx<0     // else, match val with closest in-bounds val
                        ? x[0]
                        : x[x.size()-1]
                        )
                );
            sum_at_pos += input_val*w[k];
        }
        y.push_back(sum_at_pos);
    }

    return y;
};
