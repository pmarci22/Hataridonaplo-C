# Compiler and compiler flags
CC := gcc
CFLAGS := -Wall -Werror

# Source files
SRCS := fajlkezeles.c lista.c main.c menu.c 

# Object files
OBJS := $(SRCS:.c=.o)

# Target executable
TARGET := hataridonaplo

# Default target
all: $(TARGET)

# Rule to link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rules to compile source files into object files with their dependencies
fajlkezeles.o: fajlkezeles.c debugmalloc.h struktura.h lista.h
	$(CC) $(CFLAGS) -c $< -o $@

lista.o: lista.c struktura.h lista.h debugmalloc.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c debugmalloc.h lista.h struktura.h menu.h fajlkezeles.h
	$(CC) $(CFLAGS) -c $< -o $@

menu.o: menu.c debugmalloc.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the directory
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
