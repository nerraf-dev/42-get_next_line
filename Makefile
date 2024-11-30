# Compiler and Flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin) # macOS
	CC = gcc
else
	CC = clang # Default to clang for other systems, including 42's
endif

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Target executable
TARGET = main

# Source files
SRCS = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = get_next_line/get_next_line.h

# Default rule
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to build and run the program with valgrind for leak checking
leak_check: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET) $(ARGS)

# Phony targets
.PHONY: all clean leak_check