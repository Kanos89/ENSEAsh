
#ifndef QUESTION6_H
#define QUESTION6_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_ARGS 100
#define BUFF_SIZE 256

void q6(const char *input, int *last_status);
#endif //QUESTION6_H
