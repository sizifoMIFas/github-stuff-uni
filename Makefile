CXX = g++
CXXFLAGS = -std=c++17 -O2
SRC = $(wildcard *.cpp)
HDR = $(wildcard *.h)

all: main_list main_vector

main_list: $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o main_list

main_vector: $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -DUSE_VECTOR $(SRC) -o main_vector

clean:
	rm -f main_list main_vector nerdai_* nelaimingi_*

.PHONY: all clean
