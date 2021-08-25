#include "shell_header.h"
/*debugging*/
void print_pid();
/*end debugging*/
int exit_shell()
{
		print_pid();
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

/**
 * _strlen - determines how long a string is
 * @s: the input string to measure
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int count;

	for (count = 0; *(s + count) != '\0'; count++)
	{}
	return (count);
}

/*added only for debugging*/
void print_pid()
{
    pid_t my_pid;
	pid_t my_ppid;

    my_pid = getpid();
	my_ppid = getppid();
    printf("%u\n %u\n", my_pid, my_ppid);
}