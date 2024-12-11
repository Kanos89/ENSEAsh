#ifndef QUESTION2_H
#define QUESTION2_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

// Prompt constants
#define PROMPT "enseash % "


void q2(char *command, int *last_status);
void read_command(char *command, size_t size);
void execute_command(const char *command);
#endif // QUESTION2_H
