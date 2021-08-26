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
