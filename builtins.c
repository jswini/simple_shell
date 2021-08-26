#include "shell_header.h"

int exit_shell(paths *path, char **arr, char *buffer)
{
		free_list(path);
		free(arr);
		free(buffer);
		fflush(stdin);
		exit(EXIT_SUCCESS);
}

void print_env()
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}	
}
