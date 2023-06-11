#include "main.h"

char *_getenv(const char *name);

/**
 * _which - finds the path of executable command in the PATH variable
 *
 * @av: string pointer that contain command
 * Return: string pointer to the path
 */

char *_which(char *av)
{
	char *path, *filename, *c_path, **arr;
	struct stat sb;
	int i = 0;
	char env[] = "PATH";

	filename = av;
	path = _getenv(env);
	if (!path)
		return (NULL);
	arr = split_words(path, ':');
	if (!arr)
		return (NULL);

	while (arr[i])
	{
		c_path = malloc(sizeof(char) * (strlen(filename) + strlen(arr[i]) + 2));
		strcpy(c_path, arr[i]);
		c_path = strcat(c_path, "/");
		c_path = strcat(c_path, filename);
		if (stat(c_path, &sb) == 0)
		{
			free_array(arr);
			return (c_path);
		}
		free(c_path);
		i++;
	}
	free_array(arr);
	return (NULL);
}


/**
 * free_array - free an array
 *
 * @arr: the array to be freed
 * Return: void
 */

void free_array(char **arr)
{
	int  i = 0;

	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}
