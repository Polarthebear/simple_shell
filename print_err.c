#include "shell.h"

/**
 * err - print an error message to stderr and exits
 * @message: error message to be printed
 * @av: name of the command that caused the error
 *
 */

void err(const char *message, char *av)
{
	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

