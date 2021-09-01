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
		write(1, "invalid input for exit\n", 23);
		return (1);
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
	int i, exit_val = EXIT_SUCCESS;
	char *arg;

	if (arr[2] != NULL)
		return;
	if (arr[1] != NULL)
	{
		arg = (char *)arr[1];
		for (i = 0; arg[i] != '\0'; i++)
		{
			if (arg[i] < '0' || arg[i] > '9')
				return;
		}
		exit_val = _atoi(arr[1]);
	}
	free_list(path);
	free(arr);
	free(buffer);
	fflush(stdin);
	exit(exit_val);
}

/**
 * print_env - prints the current enviroment
 */

void print_env(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
}
/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: the converted integer
 */

int _atoi(char *s)
{
	int i, l, n, sign;

	n = 0;
	sign = 1;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	l = i;
	for (i = 0; i < l; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			if ((n * -10) - (s[i] - 48) == -2147483648)
			{
				n = (n * -10) - (s[i] - 48);
				return (n);
			}
			n = n * 10 + (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
	}
	return (n * sign);
}
