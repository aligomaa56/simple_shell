#include "main.h"

/**
 * main - the shell
 * @argv: arguments
 * @ac: arguments
 * @environment: environment
 * Return: 0
 */

int main(__attribute__((unused))int ac, char **argv, char **environment)
{
	char *usr_inpt, **tokens;
	int status = 0, com_count = 0;

	while (1)
	{
		usr_inpt = _getline();
		if (usr_inpt == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (status);
		}
		com_count++;

		tokens = tok_tok(usr_inpt);
		if (!tokens)
		{
			continue;
		}

		if (isblt(tokens[0]))
		{
			bltin_func(tokens, argv, &status, com_count, environment);
		}
		else
		{
			status = _exec(tokens, argv, environment, com_count);
		}
	}
}
