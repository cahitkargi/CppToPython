# An example Python binding to C++

This example creates a class in C++ (`cppLooper`) and uses it in Python.
`cppLooper` class is used to run a simple loop, and we can compare the performances by running the same loop in Python 
(see `testCppPython.ipynb`).

**I will add comments/explanations into the source code and update this README later.** 
But, for now, the provided `makefile` can be used to compile the shared library to use it in `testCppPython.ipynb` or to compile the main program C++ program (see `main.cc`).

- to compile the shared library for Python
     ```console
    make pyBind 
    ```
- to compile and execute the main.cc 
    ```console
    make main 
    ```


