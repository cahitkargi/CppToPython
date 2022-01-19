#include "cppLooper.hpp"

#ifndef PUBLIC_FUNC
#define PUBLIC_FUNC __attribute__((visibility("default")))
#endif

int returnC(){
    return 3;
}

extern "C" {
    CppLooper* PUBLIC_FUNC CppLooper_new(){ return new CppLooper(); }
    //void PUBLIC_FUNC CppLooper_del(CppLooper* cppl){ delete cppl; }

    int PUBLIC_FUNC CppLooper_getLCount(CppLooper* cppl){ return cppl->getLCount(); }
    void PUBLIC_FUNC CppLooper_setLCount(CppLooper* cppl, int lc){ cppl->setLCount(lc); }

    bool PUBLIC_FUNC CppLooper_getLCpow(CppLooper* cppl){ return cppl->getLCpow(); }
    void PUBLIC_FUNC CppLooper_setLCpow(CppLooper* cppl, bool lc){ cppl->setLCpow(lc); }

    void PUBLIC_FUNC CppLooper_loopIt(CppLooper* cppl){ cppl->loopIt(); }
}