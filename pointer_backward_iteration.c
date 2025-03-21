#include <stdio.h>
#include <stdlib.h>

/*
    Program: Reverse Array Using Pointers
    Description:
        - This program initializes a fixed-size 1D array.
        - It prints the array in reverse order using pointer arithmetic.
        - Instead of direct indexing (a[i]), it accesses elements using *(a + i).
        - The loop iterates backward from the last element to the first.
*/

int main() {
    int a[5] = {10, 20, 30, 40, 50};

    // Looping backward using pointer arithmetic
    for (int i = 5 - 1; i >= 0; i--) {
        printf("%d ", *(a + i));
    }

    printf("\n"); // Newline for cleaner output
    return 0;  // Explicit return
}
