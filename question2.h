#ifndef QUESTION2_H
#define QUESTION2_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h> // for the waitpid


#define PROMPT "enseash % "
#define PROMPT_LENGTH (sizeof(PROMPT) - 1)

// Buffer size for command input
#define BUFF_SIZE 128

void q2(char *command);

#endif // QUESTION2_H
