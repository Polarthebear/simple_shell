#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
void err(const char *message, char *av);
ssize_t prompt(char **input);
char **split(const char *input);
int exec(char *agrv[]);
#endif


