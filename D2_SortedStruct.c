/*
    Program: Student Grade Sorting System
    Description: 
        - This program accepts a list of students, including their names and two grades.
        - It calculates the total grades for each student and sorts them in descending order.
        - The sorted list is then displayed with names and total grades.
    
    Features:
        - Input validation for names and grades
        - Uses structs to store student data
        - Implements Selection Sort to order students by total grades
*/

#include <stdio.h>
#include <ctype.h> // isalpha function, used for error checking
#include <string.h> // strcpy, used for swapping names

// Function to check if a string contains only letters
int strErrorCheck (char *name, int strCount) {
    strCount = 0;
    while (*name) {
        if (!isalpha (*name)) // Checks if the character is not a letter
            strCount++;
        name++;
    }
    return strCount;
}

// Structure to store student details
typedef struct {
    char name[20]; // Student's name
    float gr1; // First grade
    float gr2; // Second grade
    float totalGrades; // Total of both grades
} Students;

int main() {
    int sSize, sizeError; // Variable for class size and input validation
    printf("Please Input Class Size: ");
    sizeError = scanf("%d", &sSize);

    // Ensures user inputs a valid integer
    while (sizeError != 1) {
        while (getchar() != '\n'); // Clears input buffer
        printf("Please Input Class Size: ");
        sizeError = scanf("%d", &sSize);
    }

    Students log[sSize]; // Array of student structs
    int strCount, gr1Count, gr2Count; // Error counters

    // Loop to get student details
    for (int i = 0; i < sSize; i++) {
        // Input student name with error checking
        printf("Student Name[%d]: ", i + 1);
        scanf("%s", log[i].name);
        strCount = strErrorCheck (log[i].name, strCount);
        while (strCount != 0) {
            while (getchar() != '\n');
            printf("Letters Only! Student Name [%d]: ", i + 1);
            scanf("%s", log[i].name);
            strCount = strErrorCheck (log[i].name, strCount);
        }

        // Input first grade with error checking
        printf("Student Grade[%d][%d]: ", i + 1, 1);
        gr1Count = scanf("%f", &log[i].gr1);
        while (gr1Count != 1) {
            while (getchar() != '\n');
            printf("Number(s) Only! Student Grade[%d][%d]: ", i + 1, 1);
            gr1Count = scanf("%f", &log[i].gr1);
        }

        // Input second grade with error checking
        printf("Student Grade[%d][%d]: ", i + 1, 2);
        gr2Count = scanf("%f", &log[i].gr2);
        while (gr2Count != 1) {
            while (getchar() != '\n');
            printf("Number(s) Only! Student Grade[%d][%d]: ", i + 1, 2);
            gr2Count = scanf("%f", &log[i].gr2);
        }
        printf("\n");
    }

   // Selection Sort (Descending Order)
    for (int i = 0; i < sSize - 1; i++) {
     int min = i;

     for (int j = i + 1; j < sSize; j++) {
        if (log[min].totalGrades < log[j].totalGrades) {
            min = j;
        }
     }

     if (min != i) {
        // Swap totalGrades
        float temp = log[i].totalGrades;
        log[i].totalGrades = log[min].totalGrades;
        log[min].totalGrades = temp;

        // Swap grades
        float tempGr1 = log[i].gr1, tempGr2 = log[i].gr2;
        log[i].gr1 = log[min].gr1;
        log[i].gr2 = log[min].gr2;
        log[min].gr1 = tempGr1;
        log[min].gr2 = tempGr2;

        // Swap names correctly
        char tempName[20];
        strcpy(tempName, log[i].name);
        strcpy(log[i].name, log[min].name);
        strcpy(log[min].name, tempName);
    }
}

    // Output Student Details in Descending Order of totalGrades
    for (int i = 0; i < sSize; i++) {
        printf("STUDENT #%d\n", i + 1);
        printf("Name: %s\n", log[i].name);
        printf("Total Grade: %.2f\n\n", log[i].totalGrades);
    }
}
