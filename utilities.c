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

void kill_p(char *cmd, int status)
{
	if (strcmp(cmd, "exit") == 0)
		_exit(status);
}
