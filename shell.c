#include "main.h"



/*int __getline(char **lineptr,  FILE *stream);

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
}*/


int main(int ac __attribute__((unused)), char **av) {

	char *prompt = "#cisfun$ ", **arr;
	char *lineptr = NULL;
	int nread = 0, wstatus, i;
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
                        break;
		}
		lineptr[nread - 1] = '\0';
		arr = parsing(lineptr);
		if (!arr)
			continue;
		pid  = fork();
                if (pid != 0)
		{
 			wait(&wstatus);
			for (i = 0; arr[i] != NULL; i++)
                		free(arr[i]);
			free(arr);
		}
                else
                {
                        execve(arr[0], arr, NULL);
                        perror(av[0]);
                }
	} while (1);
	free(lineptr);
	return (0);
}


