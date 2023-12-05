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
	int i, result;
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
			result = exec(argv);
			if (result == -1)
			{
				err("No such file or directory", av[0]);
				break;
			}

			for (i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}
			free(argv);
		}
		free(input);
	}

	return (0);
}
