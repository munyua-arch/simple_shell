#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 64

void run_shell();
void denno_print(const char *habari, ...);
char *string_shell_concat(char *nyota, char *kitu, int m);
char *locate_string(char *ch, char q);
char string_shell_copy(char *nyota, char *kitu, int m);


#endif /* SHELL_H */

