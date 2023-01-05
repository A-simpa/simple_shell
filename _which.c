#include "main.h"

char *_getenv(const char *name);

char *_which(char *av)
{
	char *path, *filename, *c_path, **arr;
	struct stat sb;
	int i = 0;

	filename = av;
	path = _getenv("PATH");
	arr = split_words(path, ':');

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



void free_array(char **arr)
{
	int  i = 0;

	while(arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}
