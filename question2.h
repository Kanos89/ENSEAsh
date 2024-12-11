#ifndef QUESTION2_H
#define QUESTION2_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

// Prompt constants
#define PROMPT "enseash %% "
#define BUFF_SIZE 128

void q2(char *command, int *last_status);

#endif // QUESTION2_H
