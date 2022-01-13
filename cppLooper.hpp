#ifndef _PYBIND_ROOT_CPPLOOPER_HEADER_IMPORTED_
#define _PYBIND_ROOT_CPPLOOPER_HEADER_IMPORTED_

class CppLooper
{
private:
    int lcount{10};
    bool lcPow{};
public:
    void setLCount(int lc);
    int getLCount();

    void setLCpow(bool lb);
    bool getLCpow();

    void loopIt();

    CppLooper(/* args */);
    //Foo(int lc = 0, bool lb = false);
    ~CppLooper();
};

#endif