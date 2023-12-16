#include "shell.h"

/**
 * _atoi -  converts the initial portion of the string
 * pointed to by s to int.
 * @s: pointer to string to be converted
 *
 * Return: converted int
 */

int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

/**
 * _realloc - resizes the memory block pointed to by ptr to new_size
 * @ptr: pointer to the previously allocated memory block
 * @new_size: new size for the memory block
 *
 * Return: pointer to the new allocated memory block with the resized size
 */

#include <stdlib.h>
#include <string.h>

void *_realloc(void *ptr, size_t new_size)
{
	size_t *old_size_ptr, old_size, copy_size;
	void *new_ptr;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	old_size_ptr = (size_t *)ptr - 1;
	old_size = *old_size_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (ptr);
	}

	if (new_size < old_size)
	{
		copy_size = new_size;
	}
	else
	{
		copy_size = old_size;
	}

	memcpy(new_ptr, ptr, copy_size);

	free(ptr);
	return (new_ptr);
}

