#include "shell.h"

/**
 * *_getenv - Main entry point
 * Description: Function that fetches an environment var from PATH
 * @env_var: Environment Variable
 * Return: *env_var (Success) or NULL (Fail)
 */
char *_getenv(const char *env_var)
{
	char **env;
	size_t var_leng = _strlen(env_var);

	if (env_var == NULL || environ == NULL || *environ == NULL)
		return (NULL);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(env_var, *env, var_leng) == 0 && (*env)[var_leng] == '=')
		{
			return (&(*env)[var_leng + 1]);
		}
	}
	return (NULL);
}
