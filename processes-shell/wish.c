#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int runCommand() {
    // create a fork, run command and return exitcode.
}

void ishell() {
    // infinite loop to take user input and execute command.
    do {
        printf("wish> ");
        char *str = NULL;
        size_t size = 0;
        ssize_t len = 0;

        if ((len = getline(&str, &size, stdin)) != -1) {
            
            if (strcmp(str, "exit\n") == 0) { // remove \n and strip commands beofre processing
                exit(0);
            }

        }
        free(str);
    } while (true);
}

int main(int argc, char** argv) {
    if (argc == 1) {
        ishell();
    } else if (argc == 2) {
        // read files, parse lines and send to 
    } else {
        printf("Usage:\n");
        printf("\tInteractive shell: ./wish\n");
        printf("\tBatch Mode: ./wish <file-containing-instructions>\n");
    }
    return 0;
}