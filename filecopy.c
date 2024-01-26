#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *sourceFile, *targetFile;
    char ch;

    if (argc < 3) {
        printf("Insufficient parameters passed.\nUsage: ./filecopy <source> <target>\n");
        return 1;
    }

    sourceFile = fopen(argv[1], "r");
    if (sourceFile == NULL) {
        printf("Cannot open source file: No such file or directory\n");
        return 1;
    }

    targetFile = fopen(argv[2], "w");
    if (targetFile == NULL) {
        printf("Cannot open or create target file.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}


