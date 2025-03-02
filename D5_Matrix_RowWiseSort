#include <stdio.h>

/* 
Program Name: Row-wise Sorting of a Dynamic 2D Array

Description:
This program takes user input for a 2D matrix with dynamic row and column sizes. 
It validates inputs, sorts each row in ascending order using Bubble Sort, and 
displays the sorted matrix. Users can retry the process.

-------------------------------------------------------
Example Test Case 1:
Input:
Input row: 3
Input column: 3
Input Array Elements.
a[0][0]: 3
a[0][1]: 1
a[0][2]: 2
a[1][0]: 9
a[1][1]: 7
a[1][2]: 8
a[2][0]: 6
a[2][1]: 5
a[2][2]: 4

Output:
Sorted Matrix:
1 2 3
7 8 9
4 5 6
-------------------------------------------------------

Example Test Case 2:
Input:
Input row: 2
Input column: 4
Input Array Elements.
a[0][0]: 10
a[0][1]: 20
a[0][2]: 5
a[0][3]: 15
a[1][0]: 40
a[1][1]: 30
a[1][2]: 25
a[1][3]: 35

Output:
Sorted Matrix:
5 10 15 20
25 30 35 40
-------------------------------------------------------
*/

void error (int *n, int *eCheck) {
    while (getchar() != '\n');  // Clear input buffer
    printf("Invalid Input! Number(s) only: ");
    *eCheck = scanf("%d", n);
}

int main() {
    int getTry, tCheck;

    do {
        int row, rCheck;
        
        // User Input: Row Size
        printf("Input row: ");
        rCheck = scanf("%d", &row);
        while (rCheck != 1) {
            error(&row, &rCheck);
        }

        int col, cCheck;
        
        // User Input: Column Size
        printf("Input column: ");
        cCheck = scanf("%d", &col);
        while (cCheck != 1) {
            error(&col, &cCheck);
        }

        int a[row][col], aCheck;
        
        // User Input: Array Elements
        printf("Input Array Elements.\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("a[%d][%d]: ", i, j);
                aCheck = scanf("%d", &a[i][j]);
                while (aCheck != 1) {
                    while (getchar() != '\n');  // Clear input buffer
                    printf("Number(s) Only! Input Again: ");
                    aCheck = scanf("%d", &a[i][j]);
                }
            }
        }

        // Sorting each row using Bubble Sort
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col - 1 - j; k++) {
                    if (a[i][k] > a[i][k + 1]) {
                        int temp = a[i][k];
                        a[i][k] = a[i][k + 1];
                        a[i][k + 1] = temp;
                    }
                }
            }
        }

        // Display Sorted Matrix
        printf("Sorted Matrix:\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

        // Prompt user to retry or exit
        printf("The program is complete! Try Again?\n0 - no | 1 - yes: ");
        tCheck = scanf("%d", &getTry);
        
        // Error Checking for retry option
        while (tCheck != 1) {
            while (getchar() != '\n');  // Clear input buffer
            printf("0 or 1 Only! Input Again: ");
            tCheck = scanf("%d", &getTry);
        }

        if (getTry == 0) {
            printf("End Program? This can't be undone.\n0 - yes | 1 - no: ");
            tCheck = scanf("%d", &getTry);
            
            // Error Checking for final confirmation
            while (tCheck != 1) {
                while (getchar() != '\n');
                printf("0 or 1 Only! Input Again: ");
                tCheck = scanf("%d", &getTry);
            }

            if (getTry == 0)
                printf("Thank you for trying the program!\n");
            else
                printf("Program Runs Again!\n");
        }
        else if (getTry == 1) {
            printf("Program Runs Again!\n");
        }

    } while (getTry != 0);

    return 0;
}
