#include "question5.h"



void q5(const char *command, int *last_status) {
    struct timespec start, end;

    // Record the start time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Fork and execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // In child process: Execute the command
        execlp(command, command, NULL);
        perror("Execution failed"); // If execlp fails
        exit(127);
    } else if (pid > 0) {
        // In parent process: Wait for the child to finish
        waitpid(pid, last_status, 0);
    } else {
        // Fork failed
        perror("Fork failed");
        return;
    }

    // Record the end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the elapsed time in milliseconds
    long elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 +
                      (end.tv_nsec - start.tv_nsec) / 1000000;

    // Display prompt with exit status and execution time
    if (WIFEXITED(*last_status)) {
        printf("enseash [exit:%d|%ldms] %% ", WEXITSTATUS(*last_status), elapsed_ms);
    } else if (WIFSIGNALED(*last_status)) {
        printf("enseash [sign:%d|%ldms] %% ", WTERMSIG(*last_status), elapsed_ms);
    }
}