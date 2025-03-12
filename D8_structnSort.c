#include <stdio.h>

// Program Description:
// This program allows the user to input a list of students along with their grades.
// It dynamically stores the student data using a struct and ensures input validation.
// The program will later sort the students in descending order of grades (to be implemented).
// Created for practice with structs, arrays, input validation, and sorting.

void checkLoop (int *n, int *nCheck);

typedef struct {
    char name [20];
    float grade;
} student;

int main() {
    // INPUT 1: Number of students
    int size, sCheck;
    student log[size];  // This will cause an issue (needs dynamic allocation or fixed size)

    printf("Welcome to the program!\n\nInput class size: ");
    sCheck = scanf("%d", &size);
    checkLoop (&size, &sCheck);

    // INPUT 2: Struct elements
    int gCheck;
    for (int i = 0; i < size; i++) {
        printf("Student[%d]: ", i + 1);
        scanf ("%s", log[i].name);

        printf("Grade: ");
        gCheck = scanf ("%f", &log[i].grade);
        while (gCheck != 1) {
            while (getchar() != '\n');
            printf("Floating Points / Number(s) only! Input again: ");
            gCheck = scanf ("%f", &log[i].grade);
        }
    }

    // TODO: Sorting logic for descending order of grades

    return 0;
}

void checkLoop (int *n, int *nCheck) {
    while (*nCheck != 1) {
        while (getchar() != '\n');
        printf("Number(s) only! Input again: ");
        *nCheck = scanf ("%d", n);
    }
}
