#include <stdio.h>

// Function: bitwise
// Description: 
// This function uses the bitwise AND operator to check if the input number is odd or even. 
// It compares the last bit (least significant bit) of the number with 1.
// If the number is odd, the result is 1 (last bit is 1).
// If the number is even, the result is 0 (last bit is 0).
// 
// Arguments:
//   int n - The integer number to check
// 
// Returns:
//   1 if the number is odd, 0 if the number is even
int bitwise(int n) {
    return (n & 1); // Compare the last bit of the number to 1. If odd, return 1; if even, return 0
}

int main() {
    // Test the bitwise function
    printf("%d\n", bitwise(5));  // Output will be 1 (odd)
    return 0;
}

