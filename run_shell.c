#include "shell.h"

void run_shell() {
	char input[MAX_INPUT_LENGTH];
	size_t input_length;
	char *args[240];
	
	while (1) {
		denno_print("#cisfun$ ");

		if (fgets(input, sizeof(input), stdin) == NULL) {
			denno_print("\n");
			break;
		}
		
		input_length = strlen(input);
		if (input_length > 0 && input[input_length - 1] == '\n') {
			input[input_length - 1] = '\0';
		}
		
		pid_t child_pid = fork();
		
		if (child_pid == -1) {
			perror("fork");
		}
		
		else if (child_pid == 0) {
			args[0] = input; 
			args[1] = NULL;

			if (execve(input, args, NULL) == -1) {
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else {
			int status;
			if (waitpid(child_pid, &status, 0) == -1) {
				perror("waitpid");
			}
		}
	}
}
