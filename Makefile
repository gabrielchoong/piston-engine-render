CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDLIBS = -lGL -lGLU -lglut

SRCS = main.cpp ground.cpp structure.cpp rectangle.cpp
OBJS = $(patsubst %.cpp,build/%.o,$(SRCS))

TARGET = bin/main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

build/%.o: %.cpp | build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

bin:
	mkdir -p bin

$(TARGET): | bin

clean:
	rm -rf build bin

