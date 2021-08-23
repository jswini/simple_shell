#include "shell_header.h"
void interact();
void find_cmd(char *buffer);
/**
 * main - 
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	if (ac > 1)/*Non-interactive*/
	{
		return (0);
	}
	else /*Interactive*/
	{
		interact();
	}
	(void)av;
	return (0);
}

void interact()
{
	char *buffer;
	size_t bytes = 1;
	ssize_t num_of_char;

	buffer = malloc(sizeof(char) * bytes);
	if (!buffer)
		return;
	while (1 == 1)/*Infinate loop*/
	{
		if (write(1, "$ ", 2) < 0)
		{
			free(buffer);
			return;}
		num_of_char = getline(&buffer, &bytes, stdin);
		if (num_of_char < 0)
		{
			free(buffer);
			return;}
		find_cmd(buffer);
	}
}

void find_cmd(char *buffer)
{
	pid_t check_process;
	char **arr, *tok;
	int i = 0, status;
	char delim[] = {' ', '\n'};

	check_process = fork();
	if (check_process == 0)
	{
		arr = malloc(sizeof(buffer));
		tok = malloc(sizeof(buffer));
		tok = strtok(buffer, delim);
		for (i = 0; tok != NULL; i++)
		{
			arr[i] = tok;
			tok = strtok(NULL, delim);
		}
		arr[i] = NULL;
		for (i = 0; arr[i] != NULL; i++)
		{
			printf("%s", arr[i]);
		}
		if (execve(arr[0], arr, NULL) == -1)
			perror("execve error");
		free(arr);
	}
	else
	{
		wait(&status);
		printf("done\n");
	}
}
