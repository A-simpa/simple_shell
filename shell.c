#include "main.h"

 /*
 *int __getline(char **lineptr,  FILE *stream);
 *
 *
 *int __getline(char **lineptr,  FILE *stream)
 *{
 *	int i = 0;
 *	int nread = 0;
 *	char ch;
 *	int n = 0;
 *
 *	char *hello = malloc(sizeof(char) * 120);
 *	if (hello == NULL)
 *		return (-1);
 *
 *	while ((ch = getc(stream)) != '\n' && ch != EOF)
 *	{
 *		nread++;
 *		if (nread == n)
 *		{
 *			hello = realloc(hello, n * 2);
 *			n = n * 2;
 *
 *		}
 *		hello[i] = ch;
 *		i++;
 *	}
 *	hello[i] = '\0';
 *	if (nread == 0)
 *(	{
 *		free(hello);
 *		return -1;
 *	}
 *
 *	*lineptr = hello;
 *	return (nread);
 *}
 */


int main(int ac __attribute__((unused)), char **av)
{

	char *prompt = "#cisfun$ ", **arr;
	char *lineptr = NULL;
	int nread = 0, wstatus, count = 1, flag = 0;
	pid_t pid;
	size_t len = 0;

	do {
		if (isatty(0))
			printf("%s", prompt);

		nread = getline(&lineptr, &len, stdin);
		if (nread == -1)
		{
			if (isatty(0))
				printf("\n");
			free(lineptr);
			exit(flag);
		}
		lineptr[nread - 1] = '\0';
		arr = parsing(lineptr, av[0], count, &flag);
		if (!arr)
		{
			if (flag == -1)
				free(lineptr), exit(0);
			continue;
		}
		pid = fork();
		if (pid != 0)
		{
			wait(&wstatus);
			if (WIFEXITED(wstatus))
				flag = WEXITSTATUS(wstatus);
			free_array(arr);
		}
		else
			flag = execve(arr[0], arr, environ), perror(av[0]);
	} while (count++);
	free(lineptr);
	return (0);
}
