#include "main.h"

char *_getenv(const char *name);

char *_which(char *av)
{
	char *path;
	char *filename, *c_path;
	char **arr;
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
			return (c_path);
		}
		free(c_path);
		i++;
	}
	return (NULL);
}
