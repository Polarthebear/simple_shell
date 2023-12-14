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

int kill_p(char *cmd, char *status)
{
    if (_strcmp(cmd, "exit") == 0)
    {
        if (status == NULL || *status == '\0')
        {
            return (0);
        }
        else
        {
            return (_atoi(status));
        }
    }
    return (-1);
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

