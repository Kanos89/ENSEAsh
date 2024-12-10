#include "question3.h"



void q3(const char *command) {
    if (strcmp(command, "exit") == 0) {
        write(STDOUT_FILENO, EXIT_MESSAGE, EXIT_MESSAGE_LENGTH);
        exit(0);
    }
}

