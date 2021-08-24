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

int find_files(char** filename);
void print_env();
int exit_shell();
void interact();
void find_cmd(char *buffer);
void execute_command(char **cmd);

extern char **environ;

#endif /*SHELL_HEADER_H*/
