#include "shell_header.h"

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
	free(buffer);
}

void find_cmd(char *buffer)
{
	char **arr, *tok;
	int i = 0;
	char delim[] = {' ', '\n'};

	
	arr = malloc(sizeof(char *) * 32);
	if (!arr)
		return;
	tok = strtok(buffer, delim);
	for (i = 0; tok != NULL; i++)
	{
		arr[i] = tok;
		tok = strtok(NULL, delim);
	}
	arr[i] = NULL;
	
	if (find_files(arr) == -1)
		perror("find failed\n");
	else
	{
		execute_command(arr);
	}
	free(arr);
}

void execute_command(char **cmd)
{
	pid_t check_process;
	int i, status;

	check_process = fork();
	if (check_process < 0)
	{
		perror("fork error");
		return;
	}
	
	if (check_process == 0)
	{	
		for (i = 0; cmd[i] != NULL; i++)
		{
			if (execve(cmd[0], cmd, NULL) == -1)
				perror("execve error");
		}
	}
	else
	{
			wait(&status);
	}
}
int find_files(char **filename)
   {
    unsigned int i;
    struct stat st;

    i = 0;
    while (filename[i])
    {
        printf("%s:", filename[i]);
        if (stat(filename[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
			return (-1);
        }
        i++;
    }
    return (0);
}
