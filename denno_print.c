#include "shell.h"

/**
 * denno_print - Custom print function to write a string to standard output.
 * @habari: The string to be printed.
 *
 * This function writes the provided string 'habari' to the standard output.
 * It does not support format specifiers or variable arguments.
 *
 * Return: None.
 */

void denno_print(const char *habari) {
    write(STDOUT_FILENO, habari, strlen(habari));
}
