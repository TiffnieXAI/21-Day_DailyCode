#include <stdio.h>

// Function prototypes
void insertion(int a[], int size);
void selection(int a[], int size);
void bubble(int a[], int size);

int getTry;  // Global variable for retry mechanism

// Function to validate positive integer input
int tCheck() {
    int num;
    while (scanf("%d", &num) != 1 || num <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '\n');  // Clear input buffer
    }
    return num;
}

// Function to validate sorting choice
int getValidChoice() {
    int choice;
    while (1) {
        printf("\nChoose a sorting algorithm:\n1 - Insertion\n2 - Selection\n3 - Bubble\nChoice: ");
        if (scanf("%d", &choice) == 1 && (choice >= 1 && choice <= 3))
            return choice;
        
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
        while (getchar() != '\n');  // Clear input buffer
    }
}

int main() {
    do {
        // Input row and column with validation
        printf("Input row: ");
        int row = tCheck();

        printf("Input column: ");
        int column = tCheck();

        int a[row][column];
        int tempA[row * column];  // Flattened 1D array
        int tempIn = 0, size = row * column;

        // Input elements with validation
        printf("Input the array elements:\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                printf("a[%d][%d]: ", i, j);
                a[i][j] = tCheck();
                tempA[tempIn++] = a[i][j];
            }
        }

        // Sorting choice with validation
        int choice = getValidChoice();

        // Perform sorting based on user choice
        switch (choice) {
            case 1: insertion(tempA, size); break;
            case 2: selection(tempA, size); break;
            case 3: bubble(tempA, size); break;
        }

        // Reconstruct the sorted 2D array
        tempIn = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                a[i][j] = tempA[tempIn++];

        // Display the sorted 2D array
        printf("\nThe sorted 2D array is:\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }

        // Retry prompt with validation
        printf("\nDo you want to try again? (0 - No, 1 - Yes): ");
        getTry = tCheck();
        if (getTry == 0) {
            printf("Terminate program? (0 - Yes, 1 - No): ");
            getTry = tCheck();
            if (getTry == 0) {
                printf("Thank you for using the program!\n");
                break;
            } else {
                printf("Program restarting...\n\n");
            }
        } else {
            printf("Program restarting...\n\n");
        }

    } while (getTry != 0);

    return 0;
}

// Sorting functions remain unchanged
void insertion(int a[], int size) {
    for (int i = 1; i < size; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selection(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (a[min] > a[j]) min = j;

        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void bubble(int a[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}
