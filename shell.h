#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
int exec_with_pipe(char **argv);
void not_active(char **argv);
int _dup2(int oldfd, int newfd);
void printenv(char **env);
void kill_p(char *cmd, char *status);
void free_cmd_arg(char **arr);
void err(const char *message, char *av);
ssize_t prompt(char **input);
char **split(const char *input);
int exec(char **argv);
char *location(char *command);
#endif


