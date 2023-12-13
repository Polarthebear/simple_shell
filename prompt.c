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
	if (input == NULL)
	{
		write(STDERR_FILENO, "Null input pointer\n", 19);
		return (-1);
	}

	nr = getline(input, &len, stdin);

	if (nr == -1)
	{
		write(STDERR_FILENO, "Input reading error\n", 20);
		free(*input);
		*input = NULL;
		exit(EXIT_FAILURE);
	}

	if ((*input)[nr - 1] == '\n')
	{
		(*input)[nr - 1] = '\0';
		nr--;
	}

	return (nr);
}
