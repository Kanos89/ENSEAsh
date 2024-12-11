#include "main.h"

int main(void) {
    q1(); // Display welcome message
    int last_status = 0;

    while(1) {
        char command[256];
        q2(command, &last_status); // Display prompt and read input

        q3(command);

        q6(command, &last_status); // Execute commands with arguments
    }

    return 0;
}