# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -Wall  - this flag is used to turn on most compiler warnings
#  -c     - this flag is used to skip the linking stage
CFLAGS = -Wall -c


# find cpp files in subdirectories
#SOURCES := $(shell find . -name '*.cc')

OBJECTS := $(shell find . -name '*.o')


# find headers
#HEADERS := $(shell find . -name '*.h')

# The build target
TARGET := run

all: $(TARGET)

$(TARGET): main.o Datapool.o Player.o Game.o Dice.o
	$(CC) $(CFLAGS) -o ($TARGET) main.o Datapool.o Player.o Game.o Dice.o

main.o: main.cc Datapool.h
	$(CC) $(CFLAGS) -c main.cc Datapool.h

Datapool.o: Datapool.cc Datapool.h Player.h
	$(CC) $(CFLAGS) -c Datapool.cc Datapool.h Player.h

Player.o: Player.cc Player.h Game.h
	$(CC) $(CFLAGS) -c Player.cc Player.h Game.h

Game.o: Game.cc Game.h Dice.h
	$(CC) $(CFLAGS) -c Game.cc Game.h Dice.h

Dice.o: Dice.cc Dice.h
	$(CC) $(CFLAGS) -c Dice.cc Dice.h

clean:
	$(RM) $(OBJECTS)
	$(RM) $(TARGET)
