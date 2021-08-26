#include "shell_header.h"
/*debugging
void print_pid();
end debugging*/
int exit_shell()
{

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

/*added only for debugging
void print_pid()
{
    pid_t my_pid;
	pid_t my_ppid;

    my_pid = getpid();
	my_ppid = getppid();
    printf("%u\n %u\n", my_pid, my_ppid);
}*/
