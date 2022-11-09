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
	return (forking());
}

/**
 * forking - create a new everytime
 *
 *
 * Return: Always 0
 */


int forking(void)
{
	pid_t child_pid;
	int status;
	char **splited, *line = NULL;
	size_t n = 0;
	ssize_t char_read;

	if (2 == 3)
	{
		return -1;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		return(1);
	}
	else if (child_pid == 0)
	{
        	printf("#cisfun$ ");
        	char_read = getline(&line, &n, stdin);
		if (char_read == -1)
			kill(0, 2);
        	if (line[char_read - 1] == '\n')
                	line[char_read - 1] = '\0';
        	/*if (line[0] == 'e')
        	 *{
                 *	exit(0);
        	}*/
        	splited = _strtok(line);
        	if (execve(splited[0], splited, environ) == -1)
        	{
                	printf("./shell: No such file or directory\n");
        	}

	}
	else
	{

		wait(&status);
		forking();
	}
	return 0;
}
