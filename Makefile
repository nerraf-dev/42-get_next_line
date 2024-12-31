# Compiler and Flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin) # macOS
	CC = gcc
else
	CC = clang # Default to clang for other systems, including 42's
endif

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Default buffer size
BUFFER_SIZE ?= 42

# Target library and executable
LIBRARY = libgnl.a
TARGET = main

# Source files
SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
MAIN_SRC = quick_test.c

# Object files
OBJS = $(SRCS:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Header files
HEADERS = get_next_line/get_next_line.h

# Default rule
all: $(LIBRARY)

# Rule to create the library
$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

# Rule to compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(MAIN_OBJ) $(LIBRARY) $(TARGET)

# Rule to build and run the program with valgrind for leak checking
leak_check: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET) $(ARGS)

# Rule to compile quick_test.c for testing
test: $(LIBRARY) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(MAIN_OBJ) $(LIBRARY) -o $(TARGET)

# Phony targets
.PHONY: all clean leak_check test
