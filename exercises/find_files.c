#include "shell_header.h"

   int find_files(char **filename)
   {
    unsigned int i;
    struct stat st;

    /*if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }*/
    i = 1;
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