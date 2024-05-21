CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = parser

all: $(TARGET)

$(TARGET): parser.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) parser.o

parser.o: parser.cpp
	$(CXX) $(CXXFLAGS) -c parser.cpp

clean:
	rm -f *.o $(TARGET)