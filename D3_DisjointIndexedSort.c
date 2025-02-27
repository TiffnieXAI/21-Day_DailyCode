/*
Program: Sort Even & Odd Indexed Elements
Description:
- Sort even-indexed elements in **ascending** order.
- Sort odd-indexed elements in **descending** order.

Input:
N = 6
Arr = [3, 1, 4, 1, 5, 9]

Processing:
- Even indices (0,2,4): [3, 4, 5] → Sort Ascending → [3, 4, 5]
- Odd indices (1,3,5): [1, 1, 9] → Sort Descending → [9, 1, 1]
- Merge back: [3, 9, 4, 1, 5, 1]

Output:
3 9 4 1 5 1
*/

#include <stdio.h>

// Sorting Function (Ascending)
void evenSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

// Sorting Function (Descending)
void oddSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int max = i;
        for (int j = i + 1; j < size; j++) {
            if (a[max] < a[j]) {
                max = j;
            }
        }
        if (max != i) {
            int temp = a[i];
            a[i] = a[max];
            a[max] = temp;
        }
    }
}

// Integer Error Checker Function
int intErr(int *N, int *nErr) {
    while (*nErr != 1) {
        while (getchar() != '\n'); // Clear Input Buffer
        printf("Number(s) Only! Input N: ");
        *nErr = scanf("%d", N);
    }
    return *N;
}

int main() {
    // User Input: Array Size N
    int N, nErr;
    printf("Please Input N: ");
    nErr = scanf("%d", &N); 
    intErr(&N, &nErr);

    int a[N], aErr;
    printf("Please Input Elements.\n");

    // User Input: Array Elements
    for (int i = 0; i < N; i++) {
        printf("a[%d]: ", i);
        aErr = scanf("%d", &a[i]);
        intErr(&a[i], &aErr);
    }

    // Count Even and Odd Indexed Elements
    int evenCount = (N + 1) / 2; // Even indices: 0,2,4,... (ceil(N/2))
    int oddCount = N / 2;        // Odd indices: 1,3,5,... (floor(N/2))

    int even[evenCount], odd[oddCount];
    int j = 0, h = 0;

    // Splitting Even and Odd Indexed Elements
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            even[j++] = a[i]; // Store in even array
        else
            odd[h++] = a[i];  // Store in odd array
    }

    // Sorting
    evenSort(even, evenCount);
    oddSort(odd, oddCount);

    // Merging Back
    j = 0, h = 0;
    printf("Sorted Elements: ");
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            printf("%d ", even[j++]);
        else
            printf("%d ", odd[h++]);
    }
    printf("\n");

    return 0;
}
