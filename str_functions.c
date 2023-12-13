#include "shell.h"

/**
 * _strlen - Main entry point
 * Description: A function that checks the length of a string
 * @s: String
 * Return: length of the string
 */
int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (-1);

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * *_strcpy - Main entry point
 * Description: Function that copies a string until NULL Character
 * @dest: Destination
 * @src: Source
 * Return:POinter to dest (Success) or NULL (Fail)
 */
char *_strcpy(char *dest, const char *src)
{
	size_t src_len = _strlen(src);
	char *dest_ptr = dest;

	if (dest == NULL || src == NULL)
		return (NULL);

	if (src_len >= BUFFER_SIZE)
		return (NULL);

	while ((*dest++ = *src++) != '\0')
	{
		if ((size_t)(dest - dest_ptr) >= BUFFER_SIZE)
			return (NULL);
	}
	return (dest_ptr);
}

/**
 * _strcat - Main entry point
 * Description: Function that concatenates two strings
 * @dest: Destination
 * @src: Source
 * Return: Pointer to the concat string
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	if (dest == NULL || src == NULL)
	{
		write(STDERR_FILENO, "Error: NULL pointer detected.\n", 30);
		return (dest);
	}

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';
	return (dest);
}


/**
 * *_strcmp - Main entry point
 * Description: Function that will compare two strings
 * @s1: first string
 * @s2: second string
 * Return: 0
 */
int _strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}

	if (*s1 != *s2)
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

/**
 * *_strdup - Main entry point
 * Description: Function that duplicates a string
 * @s: string
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	size_t leng = _strlen(s) + 1;
	char *dup = malloc(leng);

	if (dup != NULL)
	{
		_strcpy(dup, s);
	}

	return (dup);
}
