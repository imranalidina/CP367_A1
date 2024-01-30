#include <stdio.h>

// Function to calculate the value of binomial coefficients
int binomialCoeff(int n, int k) {
    if (k > n - k) k = n - k;
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to print spaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++)
        printf(" ");
}

// Function to print a single line of Pascal's triangle
void printLine(int n, int maxWidth) {
    int numSpaces = (maxWidth - n) / 2; // Center the numbers
    printSpaces(numSpaces);
    for (int i = 0; i <= n; i++) {
        printf("%d ", binomialCoeff(n, i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's triangle (max 15): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 15) {
        printf("Invalid input. Please enter a positive integer less than 15.\n");
        return 1;
    }
    int maxWidth = 3 * (n - 1); // Approximate width of the last line
    for (int line = 0; line < n; line++) {
        printLine(line, maxWidth);
    }
    return 0;
}
