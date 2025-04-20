# use 'make pyBind' to create the shared library for Python
# use 'make main' to compile and execute the main.cc

CPPC := g++
CPPSTD := -std=c++17
TARGET := main
SO_FILE := pyBind
CFLAGS := -fPIC

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

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    INSTALL_NAME := -Wl,-install_name,$(SO_FILE).so
else
    INSTALL_NAME :=
endif

$(SO_FILE).so: $(O_FILES)
	$(CPPC) $(CPPSTD) -shared $(INSTALL_NAME) -o $(SO_FILE).so $(O_FILES)

.PHONY: $(SO_FILE)
$(SO_FILE): $(SO_FILE).so

clean:
	rm $(O_FILES)
