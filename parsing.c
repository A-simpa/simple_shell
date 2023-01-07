#include "main.h"

/**
 *
 *
 *
 */



char **parsing(char *lineptr, char *name, int count, int *flag)
{
	char **arr, path[] = "PATH";
	char  *cmd;
	struct stat sb;

	arr = split_words(lineptr, ' ');
	if (arr)
	{
		if (_getenv(path) == NULL)
			return(NULL);
		if (stat(arr[0], &sb) == 0)
			return (arr);
		cmd = _which(arr[0]);
		if (!cmd)
		{
			*flag = 127;
			fprintf(stderr, "%s: %d: %s: not found\n", name, count, arr[0]);
			free_array(arr);
			return (NULL);
		}
		free(arr[0]);
		arr[0] = cmd;
		return (arr);
	}
	return (NULL);
}

