#include "shell_header.h"
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;


	if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
	{
		{	
	if (find_files(av) == 0)
		printf("function success");
	else
		printf("function failed");
	}
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
	}
    return (0);
}