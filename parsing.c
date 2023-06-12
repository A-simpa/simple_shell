#include "main.h"

/**
 * parsing - does all the cleaning needed
 * to have all commands and its variable
 *
 * @lineptr: string pointer to the current input line
 * @name: name of cmd
 * @count: line count
 * @flag: indicators of sucess or failure
 * Return: returns an array of process commmand and argument
 */



char **parsing(char *lineptr, char *name, int count, int *flag)
{
	char **arr;
	char  *cmd;
	struct stat sb;

	arr = split_words(lineptr, ' ');
	if (arr)
	{
		if (stat(arr[0], &sb) == 0 && strchr(arr[0], '/'))
			return (arr);
		/*printf("got to front of builtin") */
		if (builtin_check(arr[0]) == 0)
		{
			if (arr[1] != NULL)
				*flag = _atoi(arr[1]);
			free(lineptr);
			free_array(arr);
			exit(*flag);
		}
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

