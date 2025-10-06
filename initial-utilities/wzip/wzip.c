#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int count = 0;
    char chars[2] = "";
    char prev[2] = "";

    for (int c = 1; c < argc; c++) {
        char* filename = strdup(argv[c]);
        FILE* fd = fopen(filename, "r");
        
        if (fd == NULL) {
            printf("wzip: cannot open file.\n");
            exit(1);
        }
        while (fread(&chars, 1, 1, fd)) {
            if (strcmp(chars, prev) == 0) {
                count++;
            } else {
                if (prev[0] != '\0') {
                    fwrite(&count, sizeof(int), 1, stdout);
                    fwrite(prev, 1, 1, stdout);
                }
                count = 1;
                strcpy(prev, chars);
            }
        }
        fclose(fd);
    }
    
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(prev, 1, 1, stdout);

    return 0;
}