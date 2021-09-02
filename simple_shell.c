#include "shell_header.h"

/**
 * main - main file for intiilization of the shell
 *
 * Return: execution status of the shell
 */

int main(void)
{
	paths *path;
	int status = 0;

	path = get_path();
	status = interact(path, status);
	if (path)
		free_list(path);
	return (status);
}
/**
 * interact - command line for the shell
 * @path: linked list of the directories in the PATH env variable
 * @status: current execution status of the shell
 *
 * Return: current execution status of the shell
 */
int interact(paths *path, int status)
{
	char *buffer = NULL;
	size_t bytes = 0;
	int i;

	while (1 == 1)/*Infinite loop*/
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(1, "$ ", 2) < 0)
				break;
		}
		if (getline(&buffer, &bytes, stdin) == EOF)
			break;
		for (i = 0; buffer[i] != '\n'; i++)
		{
			if (buffer[i] != ' ')
			{
				status = find_cmd(path, buffer, status);
				break;
			}
		}
	}
	free(buffer);
	return (status);
}

/**
 * find_cmd - tokenizes input from command line and searches for commands
 * @path: linked list of the directories in the PATH env variable
 * @buffer: string containing input from command line
 * @status: current execution status of the shell
 *
 * Return: current execution status of the shell
 */

int find_cmd(paths *path, char *buffer, int status)
{
	char **arr, *tok, *check_name;
	int i = 0, j = 0;
	char delim[] = {' ', '\n'};


	arr = malloc(sizeof(char *) * 32);
	if (!arr)
		return (status);
	tok = strtok(buffer, delim);
	for (i = 0; tok != NULL; i++)
	{
		arr[i] = tok;
		tok = strtok(NULL, delim);
	}
	arr[i] = NULL;
	if (check_builtins(arr, path, buffer, status) == 0)
	{
		check_name = find_files(path, arr[0]);
		if (_strcmp(check_name, arr[0]) != 0)
		{
			arr[0] = check_name;
			j = 1;
		}
		if (arr[0] == NULL)
			perror("Command not found");
		else
			status = execute_command(arr, status);
		if (j == 1)
			free(arr[0]);
	}
	free(arr);
	return (status);
}

/**
 * execute_command - executes a non-builtin command
 * @cmd: array containing the command and arguments as strings
 * @status: current execution status of the shell
 *
 * Return: current execution status of the shell
 */

int execute_command(char **cmd, int status)
{
	pid_t check_process;
	int i;

	check_process = fork();
	if (check_process < 0)
	{
		perror("Could not create child process");
		return (status);
	}
	if (check_process == 0)
	{
		for (i = 0; cmd[i] != NULL; i++)
		{
			if (execve(cmd[0], cmd, NULL) == -1)
				perror("Command could not execute");
		}
	}
	else
	{
		wait(&status);
		status = WEXITSTATUS(status);
		return (status);
	}
	return (status);
}

/**
 * find_files - checks for command file existance
 * @path: linked list of the directories in the PATH env variable
 * @filename: command to search for
 *
 * Return: full path to command or NULL on failure
 */

char *find_files(paths *path, char *filename)
{
	struct stat st;
	paths  *ptr;
	char *file;

	if (stat(filename, &st) == 0)
		return (filename);
	if (!path)
		return(NULL);
	ptr = path;
	while (ptr->next)
	{
		file = _strcat(ptr->file_path, filename);
		if (stat(file, &st) == 0)
			return (file);
		free(file);
		ptr = ptr->next;
	}
	return (NULL);
}
