#include "main.h"

int main(void) {
    // Display the welcome message
    q1();

    while (1) {
        char command[BUFF_SIZE];

        // Read the command (Question 2)
        q2(command);

        // Check and exit if the command is 'exit'
        q3(command);
    }

    return 0;
}
