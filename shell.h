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
#define BUFFER_SIZE 1024
/*Global var*/
int not_issaty(char **env);
extern char **environ;
void printenv(char **env);
int exit_(char *status);
void free_cmd_arg(char **arr);
void error(const char *message, char *av);
ssize_t prompt(char **input, size_t len);
char **token(const char *input);
int exec(char **argv);
char *location(char *command);
/*String Functions*/
void *_realloc(void *ptr, size_t new_size);
int _atoi(char *s);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *s);
/*getenv function*/
char *_getenv(const char *env_var);
#endif


