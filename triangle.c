#include <stdio.h>

// Function to print spaces
void printSpaces(int count) {
    for(int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Function to calculate factorial - used for calculating Pascal's triangle values
int factorial(int num) {
    int fact = 1;
    for (int i = 2; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the binomial coefficient
int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to print `n` rows of Pascal's triangle
void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        // Print leading spaces
        printSpaces(n - line);
        
        // Print the numbers
        for (int i = 0; i <= line; i++) {
            printf("%d ", binomialCoeff(line, i));
        }
        
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's triangle (max 15): ");
    if(scanf("%d", &n) != 1 || n <= 0 || n > 15) {
        printf("Invalid input. Please enter a positive integer less than 15.\n");
        return 1;
    }
    printPascal(n);
    return 0;
}



