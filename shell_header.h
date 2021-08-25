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

char *find_files(paths *path, char *filename);
void print_env();
int exit_shell();
void interact(paths *path);
void find_cmd(paths *path, char *buffer);
void execute_command(char **cmd);
paths *get_path(void);
void free_list(paths *head);
size_t print_list(const paths *h);
char *_strcat(char *s1, char *s2);

extern char **environ;

#endif /*SHELL_HEADER_H*/
