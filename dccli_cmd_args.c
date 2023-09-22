#include "shell.h"

/**
 * dccl_cmd_args - Execute a command with arguments.
 *
 * @cmd: The command with arguments as a string.
 *
 * This function takes a command string and tokenizes it into arguments.
 */

void dccl_cmd_args(const char *cmd)
{
	char *args[MAX_ARGS], *tk;
	int aforarg_count = 0, status;

	tk = strtok((char *)cmd, " ");
	while (tk != NULL && aforarg_count < MAX_ARGS - 1)
	{
		args[aforarg_count++] = tk;
		tk = strtok(NULL, " ");
	}
	args[aforarg_count] = NULL;
	if (aforarg_count == 0)
	{
		return;
	}
	setenv("VAR1", "val1", 1);
	setenv("VAR2", "val2", 1);

	pid_t mtoto_pid = fork();

	if (mtoto_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (mtoto_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else
	{
		waitpid(mtoto_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			denno_print("shell: %s: command not found\n", args[0]);
		}
	}
	unsetenv("VAR1");
	unsetenv("VAR2");
}
