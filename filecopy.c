#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *source, *target;
    char ch;

    if (argc != 3) {
        printf("Usage: ./filecopy <source> <target>\n");
        return 1;
    }

    source = fopen(argv[1], "r");
    if (source == NULL) {
        printf("Cannot open source file.\n");
        return 1;
    }

    target = fopen(argv[2], "w");
    if (target == NULL) {
        fclose(source);
        printf("Cannot open target file.\n");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(target);

    return 0;
}

