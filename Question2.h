//
// Created by kanos on 04/12/24.
//

#ifndef QUESTION2_H
#define QUESTION2_H
#define startline "enseash %"
#define fdw 1
#define fdr 0
#define BUFFSIZE 128
#define lenght_sl


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void read_command(char *command);
void exec_command(const char *command,int* status);
void q2(void);

#endif //QUESTION2_H



