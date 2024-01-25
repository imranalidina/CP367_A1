#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are passed
    if(argc != 3) {
        printf("Usage: %s <source> <target>\n", argv[0]);
        return 1; // Return non-zero for error code
    }

    // Open the source file for reading
    FILE *src = fopen(argv[1], "r");
    if(src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open the target file for writing
    FILE *dest = fopen(argv[2], "w");
    if(dest == NULL) {
        perror("Error opening target file");
        fclose(src); // Close the source file before exiting
        return 1;
    }

    // Copy contents from source to target
    char buffer[1024]; // A buffer to hold file contents temporarily
    size_t bytesRead;
    while((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    // Close the opened files
    fclose(src);
    fclose(dest);

    printf("File copy was successful.\n");

    return 0; // Return zero to indicate success
}
