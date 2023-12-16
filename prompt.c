#include "shell.h"

/**
 * prompt - Display a prompt and wait for the user to type a command
 * @input: string
 * @len: buffer size
 * Return: on success return number of chars read, otherwise return -1
 */

ssize_t prompt(char **input, size_t len)
{
	ssize_t nr;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
	if (input == NULL)
	{
		write(STDERR_FILENO, "Null input pointer\n", 19);
		return (-1);
	}

	nr = getline(input, &len, stdin);
	if (nr == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(*input);
		*input = NULL;
		exit(EXIT_FAILURE);
	}

	return (nr);
}
