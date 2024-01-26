#include <stdio.h>

void printSpaces(int n) {
    for(int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printPascal(int n) {
    int arr[n][n]; // Create a 2D array to store the values of Pascal's triangle

    // Initialize the first column and diagonal values to 1
    for(int line = 0; line < n; line++) {
        arr[line][0] = 1;
        arr[line][line] = 1;
    }

    // Calculate the other values using the sum of the two values above it
    for(int line = 2; line < n; line++) {
        for(int i = 1; i < line; i++) {
            arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
        }
    }

    // Print the triangle
    for(int line = 0; line < n; line++) {
        printSpaces(n - line - 1); // Print leading spaces
        for(int i = 0; i <= line; i++) {
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Please enter a value for the Pascal triangle\n");
    if(scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a positive integer less than 15.\n");
        return 1;
    }
    if(n <= 0 || n > 15) {
        printf("Invalid input. Please enter a positive integer less than 15.\n");
        return 1;
    }

    printPascal(n);
    return 0;
}
