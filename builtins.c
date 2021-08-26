#include "shell_header.h"
/**
 * check_builtins - checks for and executes builtins
 * @arr: array containing command and arguments
 * @path: linked list of the directories in the PATH env variable
 * @buffer: full command line input
 *
 * Return: 1 if a builtin completes, 0 if no builtin is found
 */
int check_builtins(char **arr, paths *path, char *buffer)
{
	if (_strcmp(arr[0], "exit") == 0)
	{
		exit_shell(path, arr, buffer);
	}
	else if (_strcmp(arr[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}

/**
 * exit_shell - exits the shell
 * @arr: array containing command and arguments
 * @path: linked list of the directories in the PATH env variable
 * @buffer: full command line input
 */

void exit_shell(paths *path, char **arr, char *buffer)
{
		free_list(path);
		free(arr);
		free(buffer);
		fflush(stdin);
		exit(EXIT_SUCCESS);
}

/**
 * print_env - prints the current enviroment
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
