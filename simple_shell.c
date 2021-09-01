#include "shell_header.h"

/**
 * main - main file for intiilization of the shell
 *
 * Return: 0
 */

int main(void)
{
	paths *path;

	path = get_path();
	interact(path);
	free_list(path);
	return (0);
}
/**
 * interact - command line for the shell
 * @path: linked list of the directories in the PATH env variable
 */
void interact(paths *path)
{
	char *buffer = NULL;
	size_t bytes = 0;
	/*ssize_t num_of_char;*/

	while (1 == 1)/*Infinite loop*/
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(1, "$ ", 2) < 0)
			{
				free(buffer);
				return;
			}
		}
		if (getline(&buffer, &bytes, stdin) == EOF)
		{
			/*write(1, "\n", 1);*/
			free(buffer);
			return;
		}
		if (buffer[0] != '\n')
			find_cmd(path, buffer);
	}
	free(buffer);
}

/**
 * find_cmd - tokenizes input from command line and searches for commands
 * @path: linked list of the directories in the PATH env variable
 * @buffer: string containing input from command line
 */

void find_cmd(paths *path, char *buffer)
{
	char **arr, *tok, *check_name;
	int i = 0, j = 0;
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
	if (check_builtins(arr, path, buffer) == 0)
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
			execute_command(arr);
		if(j == 1)
			free(arr[0]);
	}
	free(arr);
}

/**
 * execute_command - executes a non-builtin command
 * @cmd: array containing the command and arguments as strings
 */

void execute_command(char **cmd)
{
	pid_t check_process;
	int i, status;

	check_process = fork();
	if (check_process < 0)
	{
		perror("Could not create child process");
		return;
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
	}
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
