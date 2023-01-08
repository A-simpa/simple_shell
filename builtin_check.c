
#include "main.h"

/**
 *
 */


int builtin_check(const char *name)
{
  	char ex[] = "exit";

	if (strncmp(name, ex, strlen(ex)) == 0)
	{
		if (name[strlen(ex)] != '\0')
			return (-1);
		return (0);
	}
	return (-1);
}


/**int main(void)
{
	char env[] = "PATH1";
        char *p;

	p = _getenv(env);
        printf("%s", p);
        return (0);
}*/
