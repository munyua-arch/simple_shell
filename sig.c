#include "shell.h"

/**
 * get_sigint - function that handle the crtl + c call in prompt
 *
 * @sig: Signal handler
 *
 * Return: nothing
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "optimum_prime$ ", 5);
}
