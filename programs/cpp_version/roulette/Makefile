# the compiler: gcc for C program, define as g++ for C++
CC = g++
 
# compiler flags:
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -Wall
 
# The build target 
TARGET = rouletteSim
 
all: $(TARGET)
 
$(TARGET): $(TARGET).cc
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc

clean:
	$(RM) $(TARGET)
