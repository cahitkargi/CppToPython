# use 'make pyBind' to create the shared library for Python
# use 'make main' to compile and execute the main.cc

CPPC = g++
CPPSTD = -std=c++17
TARGET = main
SO_FILE = pyBind
CFLAGS = -fPIC

CPP_FILES=$(wildcard *.cpp)
O_FILES=$(CPP_FILES:.cpp=.o)


%.o : %.cpp
	$(CPPC) $(CPPSTD) -c $(CFLAGS) $< > $@

.PHONY: obfiles
obfiles: $(O_FILES)

# main
.ONESHELL:
$(TARGET): $(TARGET).cc $(O_FILES)
	$(CPPC) $(CPPSTD) -o $(TARGET) $(TARGET).cc $(O_FILES)
	./$(TARGET)


## pyBind

$(SO_FILE).so: $(O_FILES)
	$(CPPC) $(CPPSTD) -shared -Wl,-install_name,$(SO_FILE).so -o $(SO_FILE).so $(O_FILES)

.PHONY: $(SO_FILE)
$(SO_FILE): $(SO_FILE).so
	
