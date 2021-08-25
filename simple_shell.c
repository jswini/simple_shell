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
	paths *path;

	path = get_path();
	if (ac > 1)/*Non-interactive*/
	{
		return (0);
	}
	else /*Interactive*/
	{
		interact(path);
	}
	(void)av;
	free_list(path);
	return (0);
}

void interact(paths *path)
{
	char *buffer;
	size_t bytes = 1;
	ssize_t num_of_char;

	buffer = malloc(sizeof(char) * bytes);
	if (!buffer)
		return;
	while (1 == 1)/*Infinite loop*/
	{
		if (write(1, "$ ", 2) < 0)
		{
			free(buffer);
			return;
		}
		num_of_char = getline(&buffer, &bytes, stdin);
		if (num_of_char == EOF)
		{
			write(1, "\n", 1);
			free(buffer);
			return;
		}
		if (buffer[0] != '\n')
			find_cmd(path, buffer);
	}
	free(buffer);
}

void find_cmd(paths *path, char *buffer)
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
	
	for (i = 0; arr[i] != NULL; i++)
		printf("%d %s\n", i, arr[i]);
	
	if (strcmp(arr[0], "env") == 0)
		print_env();
	if (strcmp(arr[0], "exit") == 0)
		exit_shell();

	arr[0] = find_files(path, arr[0]);
	if (arr[0] == NULL)
		perror("find failed");
	else
	{
		execute_command(arr);
	}
	free(arr[0]);
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
char *find_files(paths *path, char *filename)
   {
    struct stat st;
	paths  *ptr;
	char *file;

	if (stat(filename, &st) == 0)
    {
        return (filename);
	}
    
	ptr = path;
    while (ptr->next)
    {
		file = _strcat(ptr->file_path, filename);
        if (stat(file, &st) == 0)
        {
/*			free_list(path);*/
			printf("file3: %s\n", file);
			return (file);
        }
		else
		{
			free(file);
		}
        ptr = ptr->next;
    }
    perror("file find failure");
	return (NULL);
}
