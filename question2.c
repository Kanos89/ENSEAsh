#include "question2.h"

void read_command(char *command, size_t size) {
    // Read a command from standard input
    ssize_t bytes_read = read(STDIN_FILENO, command, size - 1);
    if (bytes_read > 0) {
        command[bytes_read - 1] = '\0'; // Replace newline with null terminator
    } else {
        command[0] = '\0'; // Empty command if read fails
    }
}

void execute_command(const char *command) {
    // Fork and execute the command
    pid_t pid = fork();
    if (pid == 0) {
        execlp(command, command, NULL);
        perror("Execution failed"); // Only executed if execlp fails\n
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Wait for the child process to finish
        int status;
        waitpid(pid, &status, 0);
    } else {
        perror("Fork failed");
    }
}

void q2(char *command, int *last_status) {
    // Display the prompt based on the last exit status
    if (WIFEXITED(*last_status)) {
        printf("enseash [exit:%d] %% ", WEXITSTATUS(*last_status));
    } else if (WIFSIGNALED(*last_status)) {
        printf("enseash [sign:%d] %% ", WTERMSIG(*last_status));
    } else {
        printf("enseash %% ");
    }
    fflush(stdout);

    // Read the user input
    ssize_t bytes_read = read(STDIN_FILENO, command, BUFF_SIZE - 1);
    if (bytes_read > 0) {
        command[bytes_read - 1] = '\0'; // Replace newline with null terminator
    } else {
        command[0] = '\0'; // Set empty input
    }
}