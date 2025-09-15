# MINUS ALGORITHM - Technical Documentation

## Project Overview

This project implements a subtraction algorithm that operates without using mathematical operators, relying instead on recursion and bitwise operations. The implementation demonstrates fundamental computer science concepts including recursion, bitwise manipulation, and algorithm design.

## Core Components

### 1. Predecessor Function
- **Purpose**: Decrements a number by 1 using recursive bitwise operations
- **Implementation**: Uses XOR and bit shifting to simulate mathematical decrement
- **Algorithm Complexity**: 
  - Time: O(log n) where n is the input number
  - Space: O(log n) due to recursive call stack

### 2. Subtraction Function  
- **Purpose**: Subtracts two numbers using only the predecessor function
- **Implementation**: Recursively decrements both operands until subtrahend reaches zero
- **Algorithm Complexity**:
  - Time: O(subtrahend) - linear with respect to the number being subtracted
  - Space: O(subtrahend) due to recursive call stack

## Technical Specifications

### Input Requirements
- **Data Type**: Non-negative integers
- **Range**: Limited by system integer size and stack depth
- **Validation**: Includes underflow protection (subtrahend > minuend)

### Output Specifications
- **Success Case**: Returns the correct difference (minuend - subtrahend)
- **Error Case**: Returns -1 for underflow conditions with warning message
- **Edge Cases**: Handles zero subtraction and equal operands

### Side Effects and Limitations
1. **Stack Usage**: Deep recursion may cause stack overflow for large numbers
2. **Performance**: Linear time complexity makes it unsuitable for large computations
3. **Memory**: Recursive calls consume stack memory proportional to operand size
4. **Integer Overflow**: No protection against integer overflow in extreme cases

## Usage Examples

### Basic Compilation and Execution
```bash
# Compile the program
make

# Run with built-in test cases
make test

# Interactive mode
./minus_algorithm
```

### Sample Operations
```cpp
// Example function calls
predecessor(10)     // Returns: 9
predecessor(1)      // Returns: 0
predecessor(0)      // Returns: -1 (underflow)

subtract(15, 7)     // Returns: 8
subtract(20, 20)    // Returns: 0
subtract(5, 8)      // Returns: -1 (underflow)
```

## Algorithm Analysis

### Correctness Proof
The algorithm's correctness relies on the mathematical property:
```
a - b = (a-1) - (b-1)
```
Applied recursively until b = 0, at which point the result is a.

### Performance Characteristics
- **Best Case**: O(1) when subtrahend is 0
- **Worst Case**: O(subtrahend) when subtrahend equals minuend
- **Average Case**: O(subtrahend/2) for typical use cases

### Memory Usage
Stack frames accumulate during recursion:
- Each recursive call consumes ~64-128 bytes (system dependent)
- Maximum stack depth equals subtrahend value
- Risk of stack overflow for subtrahend > ~10,000 (system dependent)

## Testing and Validation

### Automated Test Cases
The implementation includes comprehensive test cases covering:
- Basic arithmetic operations
- Edge cases (zero operations, equal operands)
- Error conditions (underflow scenarios)
- Performance validation with larger numbers

### Test Results
All test cases pass, demonstrating:
- Functional correctness
- Proper error handling
- Expected performance characteristics

## Educational Value

This implementation serves as an educational tool demonstrating:
1. **Recursion**: How recursive algorithms can solve mathematical problems
2. **Bitwise Operations**: Low-level arithmetic without mathematical operators
3. **Algorithm Design**: Trade-offs between simplicity and efficiency
4. **Error Handling**: Robust programming practices for edge cases

## Future Enhancements

Potential improvements could include:
1. **Iterative Implementation**: Reduce stack usage with iterative approach
2. **Negative Number Support**: Extend algorithm to handle signed integers
3. **Optimization**: Implement more efficient bitwise subtraction
4. **Arbitrary Precision**: Support for numbers larger than system integers

## References

- Computer Science fundamentals: Recursion and algorithmic thinking
- Bitwise operations: Low-level arithmetic manipulation
- Algorithm analysis: Time and space complexity evaluation