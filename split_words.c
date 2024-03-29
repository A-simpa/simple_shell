#include "main.h"

/**
 * count_words - count the number of words in a string
 *
 * @str: string pointer to the string
 * @del: the delimeter to use to split
 *
 * Return: count as integer
 */

int count_words(char *str, char del)
{
	int i = 0, count = 0;

	/* Counting the number of words */
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == del)
		{
			i++;
			continue;
		}
		else if ((str[i] == del || !(str[i + 1])) && str[i - 1] != del)
			count++;
		else if ((str[i] != del && !(str[i + 1])) && str[i - 1] == del)
			count++;
		i++;
	}
	return (count);
}

/**
 * split_words - splits words at some particular delimeter
 *
 * @str: the string to split
 * @del: the delimeter to use
 *
 * Return: an array of words
 */

char **split_words(char *str, char del)
{
	int i = 0, j = 0, cond, count;
	int prev = 0, cur = 0;
	char **arr, buf;

	count = count_words(str, del);
	if (count == 0)
		return (NULL);
	arr = malloc(sizeof(char *) * (count + 1));
	while (str[i])
	{
		cond = 0;
		if (i == 0 && str[i++] == del)
			continue;
		else if ((str[i] == del || !(str[i + 1])) && str[i - 1] != del)
			cond = 1;
		else if ((str[i] != del && !(str[i + 1])) && str[i - 1] == del)
			cond  = 1;
		if (cond == 1)
		{
			cur = i;
			if (str[i + 1])
				buf = str[cur], str[cur] = '\0';
			while (str[prev] == del || str[prev] == '\n')
				prev++;
			arr[j] = malloc(sizeof(char) * (cur - prev + 2));
			if (!(arr[j]))
			{
				while (--j)
					free(arr[j]);
				free(arr[j]), free(arr);
			}
			strcpy(arr[j++], &(str[prev]));
			str[i] = buf, prev = cur;
		}
		i++;
	}
	arr[count] = NULL;
	return (arr);
}


/*
 *int main(void)
 *{
 *	char str[] = "";
 *	int count;
 *
 *	count = count_words(str, ' ');
 *	printf("%d", count);
 *}
 */































