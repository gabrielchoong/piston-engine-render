CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDLIBS = -lGL -lGLU -lglut

SRCS = \
core/init.cpp \
core/input.cpp \
core/callbacks.cpp \
core/Camera.cpp \
shapes/Cuboid.cpp \
shapes/Cylinder.cpp \
shapes/Circle.cpp \
shapes/DrawCuboid.cpp \
components/Piston.cpp \
components/structure.cpp \
main.cpp

OBJS = $(patsubst %.cpp,build/%.o,$(SRCS))

TARGET = bin/main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

build/%.o: %.cpp | build
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	mkdir -p build

bin:
	mkdir -p bin

$(TARGET): | bin

clean:
	rm -rf build bin

