#include "question6.h"
#include "main.h"

void q6(const char *input, int *last_status) {
    char *args[100];
    char input_copy[256];

    // copy from user's entry
    strncpy(input_copy, input, sizeof(input_copy) - 1);
    input_copy[sizeof(input_copy) - 1] = '\0';

    // Tokenisation of the entry
    int i = 0;
    char *token = strtok(input_copy, " ");
    while (token != NULL && i < 99) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Initialisation to record time
    struct timespec start, end;

    // Clean buffers before forking
    fflush(stdout);
    fflush(stderr);

    pid_t pid = fork();

    if (pid == 0) {

        execvp(args[0], args);

        //
        perror("Execution failed");
        exit(127);  //
    } else if (pid > 0) {
        //

        //
        clock_gettime(CLOCK_MONOTONIC, &start);
        waitpid(pid, last_status, 0);
        clock_gettime(CLOCK_MONOTONIC, &end);

        //
        long elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 +
                          (end.tv_nsec - start.tv_nsec) / 1000000;

        //
        if (WIFEXITED(*last_status)) {
            printf("[exit:%d|%ldms]\n", WEXITSTATUS(*last_status), elapsed_ms);
        } else if (WIFSIGNALED(*last_status)) {
            printf("[sign:%d|%ldms]\n", WTERMSIG(*last_status), elapsed_ms);
        }
    } else {
        //
        perror("Fork failed");
    }
}