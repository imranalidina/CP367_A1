#include <stdio.h>

void printSpaces(int count) {
    for(int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printPascal(int n) {
    int arr[n][n];

    // Initialize the first column
    for (int line = 0; line < n; line++) {
        arr[line][0] = 1;
        // Print leading spaces
        printSpaces(n - line);
        for (int i = 0; i <= line; i++) {
            // First and last values in every row are 1
            if (line == i || i == 0)
                arr[line][i] = 1;
            else // Other values are sum of values just above and left of above
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            printf("%d ", arr[line][i]);
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
