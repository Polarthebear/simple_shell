#include "shell.h"

/**
 * split - splits a string
 * @input: string to be split
 *
 * Return: an array of each word of the string
 */

char **split(const char *input)
{
	const char delim[] = " \t\n";
	char *str;
	char *word;
	char **arr;
	size_t len, i;

	len = _strlen(input);
	str = malloc(sizeof(char) * (len + 1));
	_strcpy(str, input);

	arr = malloc(sizeof(char *) * (len + 1));

	word = strtok(str, delim);
	i = 0;
	while (word != NULL)
	{
		arr[i] = malloc(sizeof(char) * (_strlen(word) + 1));
		_strcpy(arr[i], word);
		word = strtok(NULL, delim);
		i++;
	}

	free(str);

	return (arr);
}

