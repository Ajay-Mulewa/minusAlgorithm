/*
 * MINUS ALGORITHM - Subtraction without Mathematical Operators
 * 
 * OBJECTIVE:
 * This program implements subtraction of two numbers using recursion without 
 * employing any mathematical operators. It demonstrates how basic arithmetic 
 * operations can be performed using bitwise operations and recursion.
 *
 * INPUT:
 * - Two integers: minuend (number from which to subtract) and subtrahend (number to subtract)
 * - Both numbers should be non-negative for this implementation
 *
 * OUTPUT:
 * - The difference between minuend and subtrahend (minuend - subtrahend)
 * - Returns -1 if subtrahend is greater than minuend (underflow protection)
 *
 * SIDE EFFECTS:
 * - Uses recursion which may cause stack overflow for very large numbers
 * - Memory usage increases with recursion depth
 * - Time complexity: O(subtrahend) - linear with respect to the subtrahend value
 * - Space complexity: O(subtrahend) - due to recursive call stack
 *
 * ALGORITHM:
 * 1. Predecessor function decrements a number by 1 using bitwise operations
 * 2. Subtraction is performed by repeatedly calling predecessor on minuend
 *    until subtrahend becomes 0
 */

#include <iostream>
#include <cassert>

class MinusAlgorithm {
public:
    /*
     * PREDECESSOR FUNCTION
     * 
     * PURPOSE: Decrements a number by 1 using recursion without mathematical operators
     * 
     * ALGORITHM:
     * - Uses bitwise operations to find two's complement representation
     * - Recursively handles carry propagation for decrement operation
     * - Base case: when rightmost bit is 1, simply flip it to 0
     * - Recursive case: when rightmost bit is 0, flip it and recursively process remaining bits
     * 
     * INPUT: Non-negative integer n
     * OUTPUT: n decremented by 1
     * SIDE EFFECTS: Stack usage proportional to number of trailing zeros
     */
    static int predecessor(int n) {
        // Base case: if number is 0, return -1 (underflow)
        if (n == 0) {
            return -1;
        }
        
        // Base case: if the least significant bit is 1
        // Simply flip it to 0 (equivalent to subtracting 1)
        if (n & 1) {
            return n ^ 1;  // XOR with 1 flips the LSB
        }
        
        // Recursive case: LSB is 0
        // We need to borrow from higher bits
        // This is equivalent to: flip LSB to 1, and decrement the rest
        return ((predecessor(n >> 1) << 1) | 1);
    }
    
    /*
     * SUBTRACTION FUNCTION
     * 
     * PURPOSE: Subtracts subtrahend from minuend using recursion
     * 
     * ALGORITHM:
     * - Base case: when subtrahend is 0, return minuend
     * - Recursive case: decrement both numbers and recurse
     * - Uses predecessor function to avoid mathematical operators
     * 
     * INPUT: Two non-negative integers (minuend, subtrahend)
     * OUTPUT: minuend - subtrahend
     * SIDE EFFECTS: Deep recursion for large subtrahend values
     */
    static int subtract(int minuend, int subtrahend) {
        // Input validation: prevent underflow
        if (subtrahend > minuend) {
            std::cout << "Warning: Subtrahend greater than minuend. Result would be negative." << std::endl;
            return -1;  // Indicate underflow condition
        }
        
        // Base case: when subtrahend becomes 0, return the minuend
        if (subtrahend == 0) {
            return minuend;
        }
        
        // Recursive case: decrement both numbers and continue subtraction
        // This is equivalent to: (minuend - 1) - (subtrahend - 1) = minuend - subtrahend
        return subtract(predecessor(minuend), predecessor(subtrahend));
    }
    
    /*
     * DEMONSTRATION AND TESTING FUNCTION
     * 
     * PURPOSE: Demonstrates the algorithm with various test cases
     * Includes edge cases and validates correctness
     */
    static void demonstrateAlgorithm() {
        std::cout << "=== MINUS ALGORITHM DEMONSTRATION ===" << std::endl;
        std::cout << "Subtraction without mathematical operators using recursion" << std::endl << std::endl;
        
        // Test cases array: {minuend, subtrahend, expected_result}
        int testCases[][3] = {
            {10, 3, 7},      // Basic case
            {15, 8, 7},      // Another basic case  
            {20, 20, 0},     // Equal numbers
            {5, 0, 5},       // Subtract zero
            {100, 25, 75},   // Larger numbers
            {7, 7, 0},       // Same numbers
            {1, 1, 0}        // Minimal case
        };
        
        int numTests = sizeof(testCases) / sizeof(testCases[0]);
        
        for (int i = 0; i < numTests; i++) {
            int minuend = testCases[i][0];
            int subtrahend = testCases[i][1];
            int expected = testCases[i][2];
            
            std::cout << "Test Case " << (i + 1) << ":" << std::endl;
            std::cout << "  Input: " << minuend << " - " << subtrahend << std::endl;
            
            int result = subtract(minuend, subtrahend);
            std::cout << "  Output: " << result << std::endl;
            std::cout << "  Expected: " << expected << std::endl;
            std::cout << "  Status: " << (result == expected ? "PASS" : "FAIL") << std::endl;
            std::cout << std::endl;
        }
        
        // Test underflow case
        std::cout << "Underflow Test:" << std::endl;
        std::cout << "  Input: 5 - 8" << std::endl;
        int underflowResult = subtract(5, 8);
        std::cout << "  Output: " << underflowResult << std::endl;
        std::cout << "  Expected: -1 (underflow indicator)" << std::endl;
        std::cout << "  Status: " << (underflowResult == -1 ? "PASS" : "FAIL") << std::endl;
    }
    
    /*
     * PREDECESSOR FUNCTION DEMONSTRATION
     * 
     * PURPOSE: Specifically tests the predecessor function
     */
    static void demonstratePredecessor() {
        std::cout << "\n=== PREDECESSOR FUNCTION DEMONSTRATION ===" << std::endl;
        std::cout << "Decrementing numbers by 1 using recursion without mathematical operators" << std::endl << std::endl;
        
        int testNumbers[] = {10, 5, 1, 16, 8, 3, 7};
        int numTests = sizeof(testNumbers) / sizeof(testNumbers[0]);
        
        for (int i = 0; i < numTests; i++) {
            int n = testNumbers[i];
            int result = predecessor(n);
            std::cout << "predecessor(" << n << ") = " << result << std::endl;
        }
        
        // Test edge case
        std::cout << "predecessor(0) = " << predecessor(0) << " (underflow case)" << std::endl;
    }
};

/*
 * MAIN FUNCTION
 * 
 * PURPOSE: Entry point for the program demonstration
 * Executes test cases and interactive mode
 */
int main() {
    std::cout << "MINUS ALGORITHM - C++ IMPLEMENTATION" << std::endl;
    std::cout << "====================================" << std::endl << std::endl;
    
    // Demonstrate the predecessor function
    MinusAlgorithm::demonstratePredecessor();
    
    // Demonstrate the subtraction algorithm
    MinusAlgorithm::demonstrateAlgorithm();
    
    // Interactive mode for user input
    std::cout << "\n=== INTERACTIVE MODE ===" << std::endl;
    std::cout << "Enter two numbers to subtract (minuend subtrahend): ";
    
    int minuend, subtrahend;
    if (std::cin >> minuend >> subtrahend) {
        std::cout << "Computing " << minuend << " - " << subtrahend << " using recursive algorithm..." << std::endl;
        int result = MinusAlgorithm::subtract(minuend, subtrahend);
        
        if (result != -1) {
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cout << "Cannot compute: subtrahend is greater than minuend" << std::endl;
        }
    }
    
    return 0;
}