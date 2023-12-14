#include "shell.h"

/**
 * main - UNIX command line interpreter
 * @ac: number of items in av
 * @av: NULL terminated array of strings
 * @env: NULL terminated array of strings
 *
 * Return: always (0) on success
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **env)
{
	char *input, **argv;
	ssize_t nread;
	int result, exit_status;

	input = NULL;
	while (1)
	{
		nread = prompt(&input);
		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(input);
			break;
		}
		if (nread > 1)
		{
			argv = split(input);
			if (_strcmp(argv[0], "env") == 0)
			{
				printenv(env);
			}
			else
			{
				if (strchr(input, '|') != NULL)
				{
					result = exec_with_pipe(argv);
				}
				else
				{
					exit_status = kill_p(argv[0], argv[1]);
					if (exit_status != -1)
					{
						free_cmd_arg(argv);
						free(input);
						return exit_status;
					}
					result = exec(argv);
					waitpid(-1, &exit_status, 0);
					if (result != 0)
					{
						err("No such file or directory", av[0]);
						free_cmd_arg(argv);
						continue;
					}
				}
			}
			free_cmd_arg(argv);
		}
		free(input);
		if (nread == 0)
			break;
	}
	return (0);
}
