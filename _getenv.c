
#include "main.h"

/**
 * _getenv - Retrieves a the value of an existing environment variable
 * Prototype: char *_getenv(const char *name);
 * @name: name of the environment variable
 *
 * Return: the value of the environment variable, if it exists, as a string
 * otherwise, NULL.
 */


char *_getenv(const char *name)
{
	char *path = NULL;
	int i;

	if (!environ)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0)
		{
			if (*(environ[i] + strlen(name)) != '=')
				return (NULL);
			path = environ[i] + strlen(name) + 1;
			break;
		}
	}
	return (path);
}


/*
*int main(void)
*{
*	char env[] = "PATH1";
*        char *p;
*
*	p = _getenv(env);
*        printf("%s", p);
*        return (0);
*}
*/
