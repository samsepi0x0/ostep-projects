#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 16384

int main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	} 
	char* searchTerm = strdup(argv[1]);
	if (argc == 2) { // reading from stdin;
		char* line = malloc(MAX_LIMIT + 1);

		while (fgets(line, MAX_LIMIT, stdin) != NULL) {
			if (strstr(line, searchTerm) != NULL) {
				printf("%s", line);
			}
		}


	} else { // reading from multiple files;
		for (int i = 2; i < argc; i++) {
			FILE* fd = fopen(argv[i], "r");
			if (fd == NULL) {
				printf("wgrep: cannot open file\n");
				exit(1);
			}

			char* line;
			size_t lineLength = 0;

			while (getline(&line, &lineLength, fd) != -1) {
				if (strstr(line, searchTerm) != NULL) {
					printf("%s", line);
				}
			}

			free(line);

			fclose(fd);
		}
	}
	return 0;
}
