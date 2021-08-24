#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct linked_list
{
	char *file_path;
	struct linked_list *next;
} paths;

extern char **environ;

int find_files(char** filename);
char *_getenv(const char *name);
paths *add_node(paths **head, const char *str);

#endif /*SHELL_HEADER_H*/
