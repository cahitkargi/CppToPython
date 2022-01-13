#include <iostream>

#include "cppLooper.hpp"

CppLooper::CppLooper(/* args */)
{
}

// CppLooper::CppLooper(int lc, bool lb) : lcount(lc), lcPow(lb)
// {
// }

CppLooper::~CppLooper()
{
    std::cout << "deleting" << std::endl;
}

void CppLooper::setLCount(int lc){
    lcount = lc;
}
int CppLooper::getLCount(){
    return this->lcount;
}

void CppLooper::setLCpow(bool lb){
    lcPow = lb;
}
bool CppLooper::getLCpow(){
    return lcPow;
}

void CppLooper::loopIt(){
    if(lcPow){
        lcount = 1 << lcount;
    }
    int res{};
    for(int ind{}; ind < lcount; ++ind){
        res += 1;
        //continue;
    }
    std::cout << res << std::endl;
}
