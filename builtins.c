#include "shell_header.h"
/**
 * exit_shell - exits shell and ends program
 *
 * Return: exit status
 */
int exit_shell(void)
{

		fflush(stdin);
		exit(EXIT_SUCCESS);
}

/**
 * print_env - outputs all env vars
 *
 * Return: void
 */

void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
}

/**
 * _strlen - determines how long a string is
 * @s: the input string to measure
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int count;

	for (count = 0; *(s + count) != '\0'; count++)
	{}
	return (count);
}
