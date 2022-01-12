TARGET = hello 

all: $(TARGET)

$(TARGET): hello_world.o
	g++ -o $(TARGET) hello_world.o

hello_world.o: hello_world.cpp
	g++ -c hello_world.cpp