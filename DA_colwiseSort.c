#include <stdio.h>

// Functions
void nErr(int *n, int *nCheck);
void sort(int row, int col, int a[row][col]);
void printArr(int row, int col, int a[row][col]);

int main() {
    // INPUT 1: rows, columns
    int row, rCheck, col, cCheck;

    // Row size input with validation
    printf("Row size: ");
    rCheck = scanf("%d", &row);
    while (rCheck != 1 || row <= 0 || row > 10) {  // Ensures row is a valid positive integer (≤10)
        nErr(&row, &rCheck);
    }

    // Column size input with validation
    printf("Column size: ");
    cCheck = scanf("%d", &col);
    while (cCheck != 1 || col <= 0 || col > 10) {  // Ensures col is a valid positive integer (≤10)
        nErr(&col, &cCheck);
    }

    // INPUT 2: array values
    int a[row][col], aCheck;
    printf("Input array elements:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("a[%d][%d]: ", i, j);
            aCheck = scanf("%d", &a[i][j]);
            while (aCheck != 1) {  // Input validation for numbers only
                while (getchar() != '\n');  // Clear input buffer
                printf("Number(s) only! Input again: ");
                aCheck = scanf("%d", &a[i][j]);
            }
        }
    }

    // PRINT: Unsorted Array
    printf("\nUnsorted Array:\n");
    printArr(row, col, a);

    // SORT: Sorting array column-wise
    sort(row, col, a);

    // PRINT: Sorted Array
    printf("\n\nSorted Array (Column-wise):\n");
    printArr(row, col, a);

    return 0;
}

// FUNCTION: Handles invalid inputs (non-numeric)
void nErr(int *n, int *nCheck) {
    while (getchar() != '\n');  // Clear input buffer
    printf("Number(s) only! Input again: ");
    *nCheck = scanf("%d", n);
}

// FUNCTION: Column-wise Selection Sort
void sort(int row, int col, int a[row][col]) {
    for (int j = 0; j < col; j++) {  // Iterate through each column
        for (int i = 0; i < row - 1; i++) {  // Selection sort for each column
            int min = i;
            for (int k = i + 1; k < row; k++) {  
                if (a[min][j] > a[k][j])  // Find the minimum element in column
                    min = k;
            }
            if (min != i) {  // Swap if needed
                int temp = a[i][j];
                a[i][j] = a[min][j];
                a[min][j] = temp;
            }
        }
    }
}

// FUNCTION: Print array with formatted borders
void printArr(int row, int col, int a[row][col]) {
    // Print top border
    for (int j = 0; j < col; j++) {
        printf("+----");
    }
    printf("+\n");

    // Print matrix content
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("| %2d ", a[i][j]);  // Print value with formatting
        }
        printf("|\n");

        // Print row border after each row
        for (int j = 0; j < col; j++) {
            printf("+----");
        }
        printf("+\n");
    }
}
