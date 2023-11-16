#include "main.h"
/**
 * _path - make path
 * @com: command
 * @env: env
 * Return: path (string)
 */
char *_path(char *com, char **env)
{
	char *env_path, *env_path_cp, *full_path, *tok;
	struct stat state;
	int i;

	for (i = 0; com[i]; i++)
	{
		if (com[i] == '/')
		{
			if (stat(com, &state) == 0)
				return (_strdup(com));
			return (NULL);
		}
	}
	env_path = _getenv("PATH", env);
	if (!env_path)
		return (NULL);

	env_path_cp = _strdup(env_path), tok = strtok(env_path_cp, ":");
	while (tok)
	{
		full_path = malloc(_strlen(tok) + _strlen(com) + 2);
		if (full_path)
		{
			_strcpy(full_path, tok), _strcat(full_path, "/"), _strcat(full_path, com);
			if (stat(full_path, &state) == 0)
			{
				free(env_path_cp);
				free(env_path);
				return (full_path);
			}
			free(full_path);
		}
		tok = strtok(NULL, ":");
	}
	free(env_path_cp);
	free(env_path);
	return (NULL);
}
