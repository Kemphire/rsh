# Name of the binary to produce
TARGET = rsh

# Source files
SRC = ./src/main.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror 

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
