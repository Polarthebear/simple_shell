#include "shell.h"

/**
 * location - Main entry point
 * Description: Generate path for each command
 * @command: command that was passed
 * Return: Command path
 */

char *location(char *command)
{
	char *path, *cpy_path, *token_path, *file_path;
	int cmnd_leng, dir_leng;
	struct stat buff;

	path = getenv("PATH");
	if (path)
	{
		cpy_path = strdup(path);
		cmnd_leng = strlen(command);
		token_path = strtok(cpy_path, ":");
		while (token_path != NULL)
		{
			dir_leng = strlen(token_path);
			file_path = malloc(cmnd_leng + dir_leng + 2);
			if (file_path == NULL)
			{
				free(cpy_path);
				return (NULL);
			}
			strcpy(file_path, token_path);
			strcat(file_path, "/");
			strcat(file_path, command);
			if (stat(file_path, &buff) == 0)
			{
				free(cpy_path);
				return (file_path);
			}
			else
			{
				free(file_path);
				token_path = strtok(NULL, ":");
			}
		}
		free(cpy_path);
		if (stat(command, &buff) == 0)
		{
			return (command);
		}
	}
	return (NULL);
}

