#include "shell.h"

/**
 * free_cmd_arg - frees array of allocated memory
 * @arr: array of words
 *
 */

void free_cmd_arg(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
	{
		free(arr[i]);
	}
	free(arr);
}


/**
 * kill_p - terminate the calling process
 * @cmd: exit string
 * @status: exit status
 *
 */

void kill_p(char *cmd, char *status)
{
	int exit_status;

	if (_strcmp(cmd, "exit") == 0)
	{
		if (status == NULL)
		{
			_exit(0);
		}
		else
		{
			exit_status = atoi(status);
			_exit(exit_status);
		}
	}
}

/**
 * _dup2 - duplicate a file descriptor
 * @oldfd: the old file descriptor
 * @newfd: the new file descriptor
 *
 * Return: new file descriptor or -1 on error
 */

int _dup2(int oldfd, int newfd)
{
	int fd;
	if (oldfd == newfd)
	{
		return (newfd);
	}
	close(newfd);

	fd = fcntl(oldfd, F_DUPFD, newfd);
	if (fd == -1)
	{
		return (-1);
	}

	if (fd != newfd)
	{
		close(fd);
		return (-1);
	}
	return (fd);
}


/**
 * not_active - print a command when not in interactive mode
 * @argv: Array of command arguments
 *
 */

void not_active(char **argv)
{
	int i = 0;

	for (i = 0; argv[i] != NULL; i++)
	{
		write(STDOUT_FILENO, argv[i], strlen(argv[i]));
		if (argv[i + 1] != NULL)
			write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
}
