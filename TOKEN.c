#include "main.h"
/**
 * tok_tok - splits a str
 * @str: user input
 * Return: pointer or NULL
 */
char **tok_tok(char *str)
{
	char *token = NULL, *str_cp = NULL;
	char **tokens = NULL;
	int i = 0, j = 0;

	if (!str)
		return (NULL);
	str_cp = _strdup(str);
	token = strtok(str_cp, " \t\n");
	if (token == NULL)
	{
		free(str), str = NULL;
		free(str_cp), str_cp = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, " \t\n");
	}
	free(str_cp), str_cp = NULL;
	tokens = malloc(sizeof(char *) * (i + 1));
	if (!tokens)
	{
		free(str), str = NULL;
		return (NULL);
	}
	token = strtok(str, " \t\n");
	while (token)
	{
		if (_strcmp(token, "#") == 0 || token[0] == 35)
		{
			break;
		}
		tokens[j] = _strdup(token);
		token = strtok(NULL, " \t\n");
		j++;
	}
	free(str), str = NULL;
	tokens[j] = NULL;
	return (tokens);
}
/**
 * _getline - reads usr input
 * Return: str
 */
char *_getline(void)
{
	char *str = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read = getline(&str, &len, stdin);

	if (read == -1)
	{
		free(str),
		str = NULL;
	}
	return (str);
}
