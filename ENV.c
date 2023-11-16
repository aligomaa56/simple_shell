#include "main.h"
/**
 * Env - handles env
 * @com: command
 * @status: status
 * @env: env
 * Return: void
 */
void Env(char **com, int *status, char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arr(com);
	(*status) = 0;
}
/**
 * _getenv - gets var's value
 * @var: variable
 * @environment: env
 * Return: value or null
 */
char *_getenv(char *var, char **environment)
{
	char *env_cp, *varr, *val, *env;
	int i;

	for (i = 0; environment[i]; i++)
	{
		env_cp = _strdup(environment[i]);
		varr = strtok(env_cp, "=");
		if (_strcmp(varr, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(env_cp), env_cp = NULL;
			return (env);
		}
		free(env_cp), env_cp = NULL;
	}
	return (NULL);
}
