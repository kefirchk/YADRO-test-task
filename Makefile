#makefile
CC = g++
CXXFLAGS = -W -Wall -Wno-unused-parameter -Wno-unused-variable -pedantic

SOURCES1 = ./source/file.cpp ./source/exception.cpp ./source/event.cpp ./source/validator.cpp ./source/main.cpp
OBJECTS1 = $(SOURCES1:.cpp=.o)
EXECUTABLE1 = ./build/program

.PHONY: clean

all: $(SOURCES1) $(EXECUTABLE1)

$(EXECUTABLE1): $(OBJECTS1)
	$(CC) $(CXXLAGS) $(OBJECTS1) -o $@

clean:
	rm -f $(OBJECTS1) $(EXECUTABLE1)
