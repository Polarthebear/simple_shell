#include "shell.h"

/**
 * token - splits a string
 * @input: string to be split
 *
 * Return: an array of each word of the string
 */

char **token(const char *input)
{
	const char delim[] = " \t\n";
	char *str, *word, **arr;
	size_t len, i;

	len = _strlen(input);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	_strcpy(str, input);
	arr = malloc(sizeof(char *));
	if (arr == NULL)
	{
		free(str);
		return (NULL);
	}
	word = strtok(str, delim);
	for (i = 0; word != NULL; i++)
	{
		arr = _realloc(arr, (i + 1) * sizeof(char *));
		if (arr == NULL)
		{
			free(str);
			return (NULL);
		}
		arr[i] = malloc(sizeof(char) * (_strlen(word) + 1));
		if (arr[i] == NULL)
		{
			free(str);
			return (NULL);
		}
		_strcpy(arr[i], word);
		word = strtok(NULL, delim);
	}
	if (i == 0)
	{
		free(arr);
		return (NULL);
	}
	arr[i] = NULL;
	free(str);
	return (arr);
}

