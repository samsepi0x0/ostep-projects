#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    int count = 0;
    char character[2] = "";
    for (int c = 1; c < argc; c++) {
        char* filename = strdup(argv[c]);
        FILE* fd = fopen(filename, "r");

        if (fd == NULL) {
            printf("wunzip: unable to open file.\n");
            exit(1);
        }

        while (fread(&count, 4, 1, fd) != 0) {
            if (fread(character, 1, 1, fd) == 0) {
                printf("unzip: unable to process file.\n");
                exit(1);
            }
            for (int i = 0; i < count; i++) {
                printf("%c", character[0]);
            }
        }
        fclose(fd);
    }
    return 0;
}