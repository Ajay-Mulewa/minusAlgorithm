# Minus Algorithm - C++ Implementation

## Overview
A comprehensive C++ implementation that demonstrates subtraction of two numbers using **recursion without mathematical operators**. The program showcases advanced programming concepts including recursive algorithms, bitwise operations, and structured documentation.

## Features
- ✅ **Predecessor Function**: Decrements numbers by 1 using recursive bitwise operations
- ✅ **Recursive Subtraction**: Implements subtraction without arithmetic operators
- ✅ **Comprehensive Documentation**: Detailed objective, input/output specs, and side effects
- ✅ **Error Handling**: Underflow protection and input validation
- ✅ **Test Suite**: Automated testing with multiple test cases
- ✅ **Interactive Mode**: User-friendly interface for custom inputs

## Quick Start

### Build and Run
```bash
# Clone and navigate to repository
git clone https://github.com/Ajay-Mulewa/minusAlgorithm.git
cd minusAlgorithm

# Compile the program
make

# Run with automated tests
make test

# Run interactively
./minus_algorithm
```

## Algorithm Details

### Core Functions
1. **`predecessor(int n)`** - Recursively decrements a number by 1 using bitwise operations
2. **`subtract(int minuend, int subtrahend)`** - Performs subtraction using only the predecessor function

### Technical Specifications
- **Input**: Two non-negative integers
- **Output**: Difference between the numbers (minuend - subtrahend)
- **Time Complexity**: O(subtrahend) - linear with the number being subtracted
- **Space Complexity**: O(subtrahend) - due to recursive call stack
- **Error Handling**: Returns -1 for underflow conditions (subtrahend > minuend)

### Example Output
```
MINUS ALGORITHM DEMONSTRATION
Test Case 1: 10 - 3 = 7 ✅ PASS
Test Case 2: 15 - 8 = 7 ✅ PASS
Test Case 3: 20 - 20 = 0 ✅ PASS
...
Interactive Mode: Enter 25 9 → Result: 16
```

## Documentation
- **[DOCUMENTATION.md](DOCUMENTATION.md)** - Complete technical documentation
- **Inline Comments** - Comprehensive code documentation explaining objectives, inputs, outputs, and side effects
- **Function Documentation** - Detailed explanation of algorithm logic and complexity analysis

## Educational Value
This project demonstrates:
- Advanced recursion techniques
- Bitwise arithmetic operations
- Algorithm complexity analysis
- Professional code documentation standards
- Error handling and edge case management

## Project Structure
```
minusAlgorithm/
├── minus_algorithm.cpp    # Main implementation
├── Makefile              # Build system
├── DOCUMENTATION.md      # Technical documentation
└── README.md            # Project overview
```

## Contributing
Feel free to contribute improvements, optimizations, or additional test cases!
