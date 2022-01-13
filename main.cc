#include <typeinfo>
#include <iostream>
#include <chrono>

#include "cppLooper.hpp"


void measureTime(CppLooper& cppl){
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    cppl.loopIt();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
}


int main(){
    CppLooper cppl{};
    
    cppl.setLCpow(true);

    cppl.setLCount(10);
    measureTime(cppl);

    cppl.setLCount(20);
    measureTime(cppl);

    cppl.setLCount(30);
    measureTime(cppl);

    return EXIT_SUCCESS;
}