#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 16384

int main(int argc, char* argv[]) {
	if (argc == 1) {
		exit(0);
	}
	for (int i = 1; i < argc; i++) {
		FILE* fd = fopen(argv[i], "r");
		if (fd == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}	

		// read lines from file
		char* line = malloc(MAX_LIMIT);
		if (line == NULL) {
			printf("wcat: unable to allocate space.\n");
			exit(1);
		}

		while (fgets(line, MAX_LIMIT, fd) != NULL) {
			printf("%s", line);
		}

		free(line);
		fclose(fd);
	}
	return 0;
}
