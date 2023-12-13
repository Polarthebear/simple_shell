#include "shell.h"

/**
 * prompt - Display a prompt and wait for the user to type a command
 * @input: string
 * Return: on success return number of chars read, otherwise return -1
 */

ssize_t prompt(char **input)
{
	size_t len = 0;
	ssize_t nr;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}

	nr = getline(input, &len, stdin);

	if (nr == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (nr);
}
