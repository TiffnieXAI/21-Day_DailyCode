/*
    Program Description:
    This program dynamically allocates memory for an array based on user input. 
    It ensures valid input for both the array size and its elements, 
    preventing errors through input validation. The allocated memory is 
    freed after use to prevent memory leaks.

    Features:
    - User-defined array size with validation.
    - Dynamic memory allocation using malloc().
    - Input validation for both size and array elements.
    - Safe memory management with proper deallocation.
*/

#include <stdio.h>
#include <stdlib.h>

void tryAgain(int *n, int *nCheck);

int main() {
    int *arr;

    // INPUT 1: size of array
    int size, sCheck;
    printf("Input size: ");
    sCheck = scanf("%d", &size);
    while (sCheck != 1 || size <= 0) {  // Ensure a valid positive size
        tryAgain(&size, &sCheck);
    }

    // PROCESS 1: Memory Allocation
    arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program if allocation fails
    }

    // INPUT 2: array elements
    int aCheck;
    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        aCheck = scanf("%d", (arr + i));
        while (aCheck != 1) {
            tryAgain((arr + i), &aCheck);
        }
    }

    // OUTPUT: Print array elements
    printf("\nArray elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // PROCESS 2: Free allocated memory
    free(arr);

    return 0; // Ensure proper termination
}

// Function to handle incorrect input
void tryAgain(int *n, int *nCheck) {
    while (getchar() != '\n'); // Clear input buffer
    printf("Number(s) only! Input again: ");
    *nCheck = scanf("%d", n);
}
