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
/**
 * struct linked_list - sinlgy linked list
 * @file_path: full path to directory
 * @next: pointer to next node of list
 *
 * Description: list of directories in PATH variable
 */
typedef struct linked_list
{
	char *file_path;
	struct linked_list *next;
} paths;

/*simple_shell.c*/
void interact(paths *path);
void find_cmd(paths *path, char *buffer);
void execute_command(char **cmd);
char *find_files(paths *path, char *filename);
/*builtins.c*/
int check_builtins(char **arr, paths *path, char *buffer);
void exit_shell(paths *path, char **arr, char *buffer);
void print_env(void);
/*get_path.c*/
paths *get_path(void);
void free_list(paths *head);
/*string.c*/
int _strlen(char *s);
char *_strcat(char *s1, char *s2);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
/*size_t print_list(const paths *h); for debugging*/

extern char **environ;

#endif /*SHELL_HEADER_H*/
