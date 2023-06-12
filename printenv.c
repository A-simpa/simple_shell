#include "main.h"

/**
 * printenv - print environment variables
 *
 * Return: void
 */

void printenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
