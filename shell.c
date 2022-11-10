#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

extern char **environ;


/**
 * main - execve example
 *
 * Return: Always 0.
 */


int main(void)
{
	int status;
	int size;
	size_t n = 0;
	char *line = NULL;
	char **split;
	ssize_t char_read;


	while(1)
	{
		if (isatty(0) == 1)
			printf("#cisfun$ ");
		char_read = getline(&line, &n, stdin);
		/*if (char_read == -1)
			return(0); */

		if (line[char_read - 1] == '\n')
			line[char_read - 1] = '\0';
		split = _strtok(line);
		free(line);
		line = NULL;
		n = 0;
		if (fork() == 0)
		{
			if(execve(split[0], split, environ) == -1)
			{
				printf("./shell: No file or directory found\n");
			}

		}
		else
		{
			wait(&status);
		}
		size = 0;
		while(split[size] != NULL)
		{
			size++;
		}
		free_grid(split, size);
	}
}
