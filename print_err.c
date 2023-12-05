#include "shell.h"

/**
 * err - print an error message to stderr and exit with a code
 * @message: error message to be printed
 * @av: name of the command that caused the error
 *
 */

void err(const char *message, char *av)
{
	write(STDERR_FILENO, av, strlen(av));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, strlen(message));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

