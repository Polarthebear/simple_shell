#include "shell.h"

/**
 * location - Main entry point
 * Description: Generate path for each command
 * command: command that was paased
 * Return: 
 */
char *location(char *command)
{
	char *path, *cpy_path;
	char *token_path, *file_path;
	int cmnd_leng, dir_leng;
	struct stat buff;

	path = getenv("PATH");

	if (path)
	{
		/*duplicating the path string*/
		cpy_path = strdup(path);
		
		/*command length*/
		cmnd_leng = strlen(command);

		/*tokenizing the path*/
		token_path = strtok(cpy_path, ":");

		while(token_path != NULL)
		{
			dir_leng = strlen(token_path);

			/*allocating memmory to store cmnd_leng and dir_leng*/
			file_path = malloc(cmnd_leng + dir_leng + 2);

			strcpy(file_path, token_path);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buff) == 0)
			{
				free(cpy_path);

				return(file_path);
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


		return (NULL);

	}


	return (NULL);

}
