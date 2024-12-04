//
// Created by kanos on 04/12/24.
//

#include "main.h"

int sons_exec_status = 1;
char buf[BUFFSIZE];

void read_command(char *command) {
    int nbElements = read(fdr,command,sizeof(command)-1);
    command[nbElements] = '\0';
}

void exec_command(const char *command,int* status) {
    if (fork()==0){
        execlp(command,command,NULL);
        exit(EXIT_FAILURE);
    }
    else {
        wait (status);
    }
}


void q2() {
    write(fdw,startline,sizeof(startline)-1);
    read_command(buf);
    exec_command(buf,&sons_exec_status);
    }
