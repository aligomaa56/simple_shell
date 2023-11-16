#include "main.h"
/**
 * _exec - executes a command
 * @com: command
 * @argv: array of arguments
 * @env: environment
 * @com_count: number of commands
 * Return: status (int)
 */
int _exec(char **com, char **argv, char **env, int com_count)
{
	char *command;
	pid_t id;
	int status;

	command = _path(com[0], env);

	if (!command)
	{
		error(argv[0], com[0], com_count);
		free_arr(com);
		return (127);
	}
	id = fork();
	if (id == 0)
	{
		if (execve(command, com, env) == -1)
		{
			perror("execve");
		}
		free(command), command = NULL;
		free_arr(com);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(id, &status, 0) == -1)
		{
			perror("waitpid");
		}
		free(command), command = NULL;
		free_arr(com);
	}
	return (WEXITSTATUS(status));
}
