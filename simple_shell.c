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
	char **arr, *tok, *file;
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
	file = malloc(sizeof(char) * 1024);
	file = find_files(arr[0]);
	printf("file: %s\n", file);
	if (arr[0] == NULL)
		perror("find failed");
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
char *find_files(char *filename)
   {
    struct stat st;
	paths *path, *ptr;
	char *file;

	if (stat(filename, &st) == 0)
    {
        return (filename);
	}
    path = get_path();
	ptr = path;
    while (ptr->next)
    {
		file = strcat(ptr->file_path, filename);
		printf("file2: %s\n", file);
        if (stat(file, &st) == 0)
        {
			printf("file3: %s\n", file);
			free_list(path);
			return (*file);
        }
        ptr = ptr->next;
    }
    perror("file find failure");
	free_list(path);
	return (NULL);
}
