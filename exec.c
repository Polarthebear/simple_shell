#include "shell.h"

/**
 * exec - executes commands
 * @argv: array of commands
 *
 * Return: -1 on failure
 */

int exec(char *argv[])
{
	pid_t pid;
	int exe;

	pid = fork();
	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		exe = execve(argv[0], argv, NULL);
		if (exe == -1)
			return (-1);
	}
	else
	{
		wait(NULL);
	}

	return (0);
}

