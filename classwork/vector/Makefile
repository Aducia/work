CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, build/%.o, $(SRC))
TARGET = main.out 

all: $(TARGET) 	
build/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 	
$(TARGET): $(OBJS)	
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) 
clean: 
	rm -rf $(OBJS) $(TARGET)
print: 
	echo $(SRC)
	echo $(OBJS)
builddir:
