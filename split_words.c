#include "main.h"

int count_words(char *str, char del)
{
	int i = 0, count = 0;

	/** Counting the number of words */
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == del)
		{
			i++;
			continue;
		}
		else if ( (str[i] == del || !(str[i+1])) && str[i-1] != del)
			count++;
		i++;
	}
	return (count);
}

char **split_words(char *str, char del)
{
	int i = 0, j = 0, count;
	int prev = 0, cur = 0;
	char **arr, buf;

	count = count_words(str, del);
	arr = malloc(sizeof(char *) * (count + 2));
	while (str[i])
	{
		if (i == 0 && str[i++] == del)
			continue;
		else if ( (str[i] == del || !(str[i+1])) && str[i-1] != del)
		{
			cur = i;
			if (str[i + 1])
			{
				buf = str[cur];
				str[cur] = '\0';
			}

			while (str[prev] == del || str[prev] == '\n')
				prev++;
			arr[j] = malloc(sizeof(char) * (cur - prev + 2));
			if (!(arr[j]))
			{
				while (--j)
				{
					free(arr[j]);
				}
				free(arr[j]), free(arr);
			}
			strcpy(arr[j++], &(str[prev]));
			str[i] = buf;
			prev = cur;
		}
		i++;
	}
	arr[count+1] = NULL;
	return (arr);
}


/*int main(void)
{
	char str[] = "/home/vagrant/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char **arr = NULL;
	int i;

	arr = split_words(str, ':');
	for (i = 0; arr[i]; i++)
		printf("%s\n", arr[i]);
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr[i]);
        free(arr);
	return (EXIT_SUCCESS);
}*/































