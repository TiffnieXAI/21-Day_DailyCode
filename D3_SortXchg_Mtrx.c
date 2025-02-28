/*
Program: Selection Sort with Swap Count
- This program sorts an array of **N** distinct integers in **ascending order** using **selection sort**.
- It also counts and displays the **total number of swaps** made during the sorting process.

Input:
N = 5
Arr = [5, 3, 1, 4, 2]

Processing:
- **Step 1: Selection Sort with Swap Tracking**
  - Swap (1,5) → [1,3,5,4,2]
  - Swap (2,3) → [1,2,5,4,3]
  - Swap (3,5) → [1,2,3,4,5]
- **Total Swaps** = 3

Output:
Sorted Array: 1 2 3 4 5
Total Swaps: 3
*/

#include <stdio.h>

int main() {
    int getTry, gErr;
  do {
    //User Input: Array size, error checker variable
    int size, sErr;
    printf("Please Input Size: ");
    sErr = scanf("%d", &size);
    while (sErr != 1) { //Looping user input if error found
        while (getchar() != '\n');
        printf("Numbers Only! Input Size: ");
        sErr = scanf("%d", &size);
    }

    int a[size], eErr; //Initialize array, error checker variable

    printf("Input Elements.\n");
    //User Input: Array elements
    for (int i = 0; i < size; i++) {
        printf("a[%d]: ", i);
        eErr = scanf("%d", &a[i]);
        while (eErr != 1) { //Looping user input if error found
            while (getchar() != '\n');
            printf("Numbers Only! Input Element: ");
            eErr = scanf("%d", &a[i]);
        }
    }

    int swapCount = 0;
    //Sorting Algo: Selection
    for (int i = 0; i < size - 1; i++) {
        //Set the first element as the smallest value
        int min = i;

        //Intializing the index i to the index of current smallest value
        for (int j = i + 1; j < size; j++) {
            if (a[min] > a[j])
                min = j;
        }

        //Swapping actual elements
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swapCount++;
        }

    }

    //Output Swap Counter, Array Elements
    printf("Swap Counter: %d\n", swapCount);
    printf("Sorted Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("\nDo you want to try again? (0 - no, 1 - yes):  ");
    gErr = scanf("%d", &getTry);
    while (gErr != 1 || getTry > 1 || getTry < 0) { //Looping user input if error found
        while (getchar() != '\n');
        printf("Invalid Input! Input 1 or 0 Only: ");
        gErr = scanf("%d", &getTry);
    }

    if (getTry == 0) {
        printf("End Program? This can't be undone (0 - yes, 1 - no): ");
        gErr = scanf("%d", &getTry);
        while (gErr != 1 || getTry > 1 || getTry < 0) { //Looping user input if error found
            while (getchar() != '\n');
            printf("Invalid Input! Input 1 or 0 Only:  ");
            gErr = scanf("%d", &getTry);
        }
        printf("Thank you for trying the program!\n");
    }

    else if (getTry == 1) {
        printf("Continue Program!\n");
    }

 } while (getTry != 0);
}
