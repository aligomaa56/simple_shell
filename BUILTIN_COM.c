#include "main.h"
/**
 * isblt - check whether com is builtin or not
 * @com: com to check
 * Return: 0 or 1
 */
int isblt(char *com)
{
	int i;

	char *bltin_com[] = {"exit", "cd", "env", NULL};

	for (i = 0; bltin_com[i]; i++)
	{
		if (_strcmp(bltin_com[i], com) == 0)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * bltin_func - handel built-in functions
 * @com: command
 * @argv: array of arguments
 * @status: status code
 * @com_count: num of commands
 * @env:environment
 * Return: void
 */
void bltin_func(
	char **com, char **argv, int *status, int com_count, char **env)
{
	(void)com_count;
	if (_strcmp(com[0], "exit") == 0)
	{
		Exit(com, argv, status, com_count);
	}
	else if (_strcmp(com[0], "env") == 0)
	{
		Env(com, status, env);
	}
	else if (_strcmp(com[0], "cd") == 0)
	{
		cd(com, status);
	}
}
/**
 * chDir - func to change dir
 * @arr_com: list of directories to go
 * Return: void
 */
void cd(char **com, int *status)
{
	char pwd[256];
	char *home = getenv("HOME");
	char *old = getenv("OLDPWD");
	char *current = getenv("PWD");

	if (com[1] == NULL)
	{
		if (chdir(home) != 0)
		{
			perror("cd");
			*status = 1;
		}
	}
	else if (strcmp(com[1], "-") == 0)
	{
		getcwd(pwd, sizeof(pwd));
		chdir(old);
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", old, 1);
	}
	else
	{
		chdir(com[1]);
		setenv("OLDPWD", current, 1);
		getcwd(pwd, sizeof(pwd));
		setenv("PWD", pwd, 1);
	}
}
