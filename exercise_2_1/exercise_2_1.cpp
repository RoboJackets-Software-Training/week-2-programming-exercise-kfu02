#include <iostream>
#include <vector>
#include "convolution.hpp"

int main() {
    std::vector<double> x;
    std::vector<double> w;
    std::vector<double> y;
    std::vector<double> y2;
    bool pack_with_zeros = true;

    std::string s;
    std::cin >> s;
    if(s == "false") {
        pack_with_zeros = false;
    }
    std::cin >> s;
    x = readInVector(s);
    std::cin >> s;
    w = readInVector(s);

    // TODO write your code here
    // =========== START =========
    y = applyConvolution(x, w, pack_with_zeros);
    // y2 = applyConvolution(x, w, false);

    printVector("x", x);
    printVector("w", w);

    printVector(y);
    // printVector(y2);

    // =========== END ===========

    return 0;
}
