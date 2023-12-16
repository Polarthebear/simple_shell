#include "shell.h"

/**
 * main - main entry point
 * @ac: number of items in av
 * @av: NULL terminated array of strings
 * @env: NULL terminated array of strings
 *
 * Return: 0 on success, otherwise -1
 */

int main(int ac, char **av, char **env)
{
	char *input, **cmd;
	ssize_t nread;
	size_t len = 0;
	int exit_status, execute;

	(void) ac;
	(void) av;

	if (access("/dev/tty", F_OK) != 0)
	{
		return (not_issaty(env));
	}
	input = NULL;
	while (1)
	{
		nread = prompt(&input, len);
		cmd = token(input);
		if (cmd == NULL)
		{
			free(input);
			continue;
		}
		if (nread == 0)
		{
			free(input);
			break;
		}
		else if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_status = exit_(cmd[1]);
			if (exit_status != -1)
			{
				free_cmd_arg(cmd);
				free(input);
				return (exit_status);
			}
		}
		else if (_strcmp(cmd[0], "env") == 0)
		{
			printenv(env);
		}
		else
		{
			execute = exec(cmd);
			if (execute != 0)
			{
				free_cmd_arg(cmd);
				continue;
			}
		}
		free_cmd_arg(cmd);
	}
	return (0);
}
