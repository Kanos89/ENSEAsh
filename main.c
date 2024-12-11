#include "main.h"

int main(void) {
    // Display the welcome message
    q1();

    // Initialize the exit status
    int last_status = 0;

    // Start the REPL loop
    while (1) {
        char command[BUFF_SIZE];

        // Step 1: Read the command and display the prompt
        q2(command, &last_status);

        // Step 2: Handle empty input
        if (strlen(command) == 0) {
            continue; // Ignore empty commands
        }

        // Step 3: Handle 'exit' explicitly
        q3(command); // Check for "exit" and exit the shell

        // Step 4: Execute the command and measure timing
        q5(command, &last_status);
    }

    return 0;
}