#include "shell.h"

/**
 * printenv - prints the enviroment
 * @env: array of enviroment variables
 *
 */

void printenv(char **env)
{
	int i = 0;
	char *env_var;

	env_var = env[i];
	while (env_var != NULL)
	{
		write(STDOUT_FILENO, env_var, _strlen(env_var));
		write(STDOUT_FILENO, "\n", 1);
		i++;
		env_var = env[i];
	}
}



