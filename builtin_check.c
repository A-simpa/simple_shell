
#include "main.h"

/**
 *builtin_check - checks if a command is a built-in
 *
 *@cmd: cmd used
 */


int builtin_check(const char *cmd)
{
  	char ex[] = "exit";
	if (strncmp(cmd, ex, strlen(ex)) == 0)
	{
		/*printf("exit found\n")*/;
		if (cmd[strlen(ex)] != '\0')
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
