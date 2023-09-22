#include "shell.h"

/**
 **string_shell_copy - functions that copies a string
 *@nyota:  destination string
 *@kitu: source string
 *@m:  no  of characters to be copied
 *Return:  concat string
 */

char string_shell_copy(char *nyota, char *kitu, int m)
{
	int a, b;
	char *ptr = nyota;

	a = 0;
	while (kitu[a] != '\0' && a < m - 1)
	{
		nyota[a] = kitu[a];
		a++;
	}
	if (a < m)
	{
		b = a;
		while (b < m)
		{
			nyota[b] = '\0';
			b++;
		}
	}
	return (ptr);
}

/**
 **string_shell_concat - function that concatenates two strings
 *@nyota: first string
 *@kitu: second string
 *@m: the no of bytes to be used
 *Return: concatenated string
 */
char *string_shell_concat(char *nyota, char *kitu, int m)
{
	int a, b;
	char *ptr = nyota;

	a = 0;
	b = 0;
	while (nyota[a] != '\0')
		a++;
	while (kitu[b] != '\0' && b < m)
	{
		nyota[a] = kitu[b];
		a++;
		b++;
	}
	if (b < m)
		nyota[a] = '\0';
	return (ptr);
}

/**
 **locate_string - function that locates a character in a string
 *@ch: the string  parsed
 *@q: character
 *Return: (ch)  ptr to  memory area
 */
char *locate_string(char *ch, char q)
{
	do {
		if (*ch == q)
			return (ch);
	} while (*ch++ != '\0');

	return (NULL);
}
