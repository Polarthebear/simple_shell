#include "shell.h"

/**
 * main -  UNIX command line interpreter
 * @ac: number of items in av
 * @av: NULL terminated array of strings
 * @env: NULL terminated array of strings
 *
 * Return: always (0) on success
 */

int main(int ac, char **av, char **env)
{
	char *input, **argv;
	ssize_t nread;
	int result;
	(void) ac;
	(void) env;

	while (1)
	{
		input = NULL;
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
			kill_p(argv[0], -1);
			result = exec(argv);
			if (result == -1)
			{
				err("No such file or directory", av[0]);
				break;
			}
			free_cmd_arg(argv);
		}
		free(input);
	}
	return (0);
}
