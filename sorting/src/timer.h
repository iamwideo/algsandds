#ifndef INCLUDE_TIMER
#define INCLUDE_TIMER

#include <string>
#include <chrono>
#include <iostream>


struct Timer {
    std::string _alg;
    int _inputSize;
    std::chrono::high_resolution_clock::time_point _start;

    Timer(const std::string& alg, int inputSize);

    ~Timer();
};

#endif
