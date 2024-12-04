//
// Created by kanos on 04/12/24.
//
#include "Question3.h"
void q3(char *command) {
    if (command=="exit") {
        write(1,exit_message,sizeof(exit_message)-1);
        exit(0);
    }
}