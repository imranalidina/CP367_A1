#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are passed
    if (argc != 3) {
        printf("Insufficient parameters passed.\n");
        return 1; // Return non-zero for error code
    }

    // Open the source file for reading
    FILE *src = fopen(argv[1], "r");
    if (src == NULL) {
        perror("Cannot open source file");
        return 1;
    }

    // Open the target file for writing
    FILE *dest = fopen(argv[2], "w");
    if (dest == NULL) {
        perror("Cannot open destination file");
        fclose(src); // Close the source file before exiting
        return 1;
    }

    // Copy contents from source to target
    char buffer[1024]; // A buffer to hold file contents temporarily
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    // Close the opened files
    fclose(src);
    fclose(dest);

    printf("The contents of file %s have been successfully copied into the %s file.\n", argv[1], argv[2]);

    return 0; // Return zero to indicate success
}
