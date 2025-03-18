/* Program: Student Database with Structures
* Basic structure program that accepts
* name, age, and grade as user input
* in a struct and displays the details.
*/

#include <stdio.h>
#include <ctype.h>

// Function to count non-alphabetic characters in a name
int strErr (char name[], int name_err) {
    name_err = 0;
    while (*name) {
        if (!isalpha(*name))
          name_err++;
        name++;
    }
    return name_err;
}

// Declare Student structure to store student details
typedef struct {
    char name[50];  // Holds student's name
    int age;        // Holds student's age
    float grade;    // Holds student's grade
} Student;

int main() {

    // Declare variable for class size and accept user input
    int n;
    printf("Input Class Size: ");
    int n_error = scanf("%d", &n);
    while (n_error != 1) {  // Input validation for class size
        while (getchar() != '\n');  // Clear input buffer
        printf("Invalid Input! Try Again: ");
        n_error = scanf("%d", &n);
    }

    Student info[n];  // Declare an array of Student structures

    int name_err, age_err, gr_err;  // Variables for error handling
    for (int i = 0; i < n; i++) {
        // Prompt for student details
        printf("STUDENT #%d\n", i + 1);

        // User Input: Name
        do {
            printf("Student Name: ");
            scanf("%s", info[i].name);
            name_err = strErr(info[i].name, name_err);  // Validate name
            if (name_err > 0)
                printf("Letters Only! Try Again.\n");
        } while (name_err > 0);

        // User Input: Age
        printf("Student Age: ");
        age_err = scanf("%d", &info[i].age);
        while (age_err != 1) {  // Input validation for age
            while (getchar() != '\n');  // Clear input buffer
            printf("Invalid Input! Try Again: ");
            age_err = scanf("%d", &info[i].age);
        }

        // User Input: Grade
        printf("Student Grade: ");
        gr_err = scanf("%f", &info[i].grade);
        while (gr_err != 1) {  // Input validation for grade
            while (getchar() != '\n');  // Clear input buffer
            printf("Invalid Input! Try Again: ");
            gr_err = scanf("%f", &info[i].grade);
        }
        printf("\n");
    }

    // Display student details
    for (int i = 0; i < n; i++) {
        printf("STUDENT #%d\n", i + 1);
        printf("Student Name:\t%s\nStudent Age:\t%d\nStudent Grade:\t%.2f\n",
                info[i].name, info[i].age, info[i].grade);
        printf("****************************\n");
    }
}
