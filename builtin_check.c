
#include "main.h"

/**
 * builtin_check - checks if a command is a built-in
 *
 * @cmd: cmd used
 * Return: int 0 for true and -1 for false
 */


int builtin_check(const char *cmd)
{
	char ex[] = "exit", env[] = "env";

	if (strncmp(cmd, ex, strlen(ex)) == 0)
	{
		/*printf("exit found\n")*/
		if (cmd[strlen(ex)] != '\0')
			return (-1);
		return (0);
	}
	else if (strncmp(cmd, env, strlen(env)) == 0)
	{
		if (cmd[strlen(ex)] != '\0')
			return (-1);
		return (1);
	}
	return (-1);
}

 /*
 *int main(void)
 *{
 *	char env[] = "PATH1";
 *      char *p;
 *
 * p = _getenv(env);
 *      printf("%s", p);
 *       return (0);
 *}
 */
