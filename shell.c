#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"





int __getline(char **lineptr,  FILE *stream);

int __getline(char **lineptr,  FILE *stream)
{
	int i = 0;
	int nread = 0;
	char ch;
	int n = 0;

	char *hello = malloc(sizeof(char) * 120);
	if (hello == NULL)
		return (-1);

	while ((ch = getc(stream)) != '\n' && ch != EOF)
	{
		nread++;
		if (nread == n)
		{
			hello = realloc(hello, n * 2);
			n = n * 2;
		}
		hello[i] = ch;
		i++;
	}
	hello[i] = '\0';
	if (nread == 0)
	{
		free(hello);
		return -1;
	}

	*lineptr = hello;
	return (nread);
}


int main(int ac __attribute__((unused)),  char **av) {

	char *prompt = "#cisfun$ ";
	char *lineptr = NULL, *argv[] = {NULL, NULL};
	int nread;
	int wstatus;
	pid_t pid;

	do {
		printf("%s", prompt);
		nread = __getline(&lineptr, stdin);
		if (nread == -1)
			return (0);

		argv[0] = lineptr;
		pid = fork();
		if (pid != 0)
		{
			wait(&wstatus);
		}
		else
		{
			execve(argv[0], argv, NULL);
			perror(av[0]);
		}
		free(lineptr);
		/*if (pid == 0)
			printf("I am child\n");
		else if (pid != 0)
			printf("I am parent\n");*/
	} while (1 && isatty(0));
	free(lineptr);
	return (0);
}
