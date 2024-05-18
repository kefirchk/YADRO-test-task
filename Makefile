#makefile
CC = gcc
CFLAGS = -W -Wall -Wno-unused-parameter -Wno-unused-variable -std=c++11 -pedantic

SOURCES1 = ./source/main.cpp ./source/file.cpp ./source/table.cpp ./source/exception.cpp ./source/event.cpp ./source/client.cpp
OBJECTS1 = $(SOURCES1:.c=.o)
EXECUTABLE1 = ./build/main

.PHONY: clean

all: $(SOURCES1) $(EXECUTABLE1)

$(EXECUTABLE1): $(OBJECTS1)
	$(CC) $(CFFLAGS) $(OBJECTS1) -o $@

clean:
	rm -f $(OBJECTS1) $(EXECUTABLE1)
