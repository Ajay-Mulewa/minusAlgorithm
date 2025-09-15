# Makefile for Minus Algorithm Project
# 
# OBJECTIVE: Build system for the minus algorithm implementation
# Provides targets for compilation, execution, and cleanup

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O2
DEBUG_FLAGS = -g -DDEBUG

# Target executable
TARGET = minus_algorithm
SOURCE = minus_algorithm.cpp

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(SOURCE)
	@echo "Building $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)
	@echo "Build successful!"

# Debug build
debug: $(SOURCE)
	@echo "Building debug version..."
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -o $(TARGET)_debug $(SOURCE)
	@echo "Debug build successful!"

# Run the program
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Run with predefined input
test: $(TARGET)
	@echo "Running automated test..."
	echo "15 7" | ./$(TARGET)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(TARGET) $(TARGET)_debug
	@echo "Clean complete!"

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  debug   - Build debug version"
	@echo "  run     - Build and run the program"
	@echo "  test    - Run with predefined input"
	@echo "  clean   - Remove build artifacts"
	@echo "  help    - Show this help message"

.PHONY: all debug run test clean help