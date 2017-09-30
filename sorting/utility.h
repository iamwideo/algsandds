#ifndef UTILITY
#define UTILITY

#include <string>
#include <chrono>
#include <iostream>

struct Timer {
    std::string _alg;
    int _inputSize;
    std::chrono::high_resolution_clock::time_point _start;
    Timer(const std::string& alg, int inputSize) {
        _alg = alg;
        _inputSize = inputSize;
        _start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        std::chrono::high_resolution_clock::time_point end =
                std::chrono::high_resolution_clock::now();
        std::cout << _alg << " with input " << _inputSize
              << " took " <<
              std::chrono::duration_cast<std::chrono::milliseconds>(end-_start).count()
              << std::endl;
    }
};

#endif
