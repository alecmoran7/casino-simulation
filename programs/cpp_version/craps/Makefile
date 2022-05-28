NAME = craps_oop

# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -Wall  - this flag is used to turn on most compiler warnings
#  -c     - this flag is used to skip the linking stage
#  -fsyntax-only - this flag is used to skip making precompiled header files for faster compiling
CFLAGS = -Wall -g -std=c++11


# find cpp files in subdirectories
#SOURCES := $(shell find . -name '*.cc')

OBJECTS := main.o Datapool.o Player.o Game.o Dice.o


# find headers
#HEADERS := $(shell find . -name '*.h')

# The build target
TARGET := run

all: $(TARGET)

#$(TARGET): main.o Datapool.o
#	$(CC) $(CFLAGS) -o $(TARGET) main.cc

main.o: main.cc
	$(CC) $(CFLAGS) -c main.cc
#
Datapool.o: Player.o
	$(CC) $(CFLAGS) -c Datapool.cc
#
Player.o: Game.o
	$(CC) $(CFLAGS) -c Player.cc
#
Game.o: Dice.o
	$(CC) $(CFLAGS) -c Game.cc
#
Dice.o: Dice.cc
	$(CC) $(CFLAGS) -c Dice.cc

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)
