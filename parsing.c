#include "main.h"

/**
 *
 *
 *
 */




char **parsing(char *lineptr)
{
	char **arr;
	char  *cmd;
	struct stat sb;

	arr = split_words(lineptr, ' ');
	if (arr)
	{
		 if (stat(arr[0], &sb) == 0)
			return (arr);
		cmd = _which(arr[0]);
		if (!cmd)
			return (NULL);
		free(arr[0]);
		arr[0] = cmd;
		return (arr);
	}
	return (NULL);
}

