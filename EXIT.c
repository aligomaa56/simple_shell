#include "main.h"
/**
 * error - print error msg
 * @argv: arguments
 * @com: command
 * @com_count: counter
 * Return: void
 */
void error(char *argv, char *com, int com_count)
{
	char *i, msg[] = ": not found\n";

	i = _itoa(com_count);
	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, com, _strlen(com));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(i);
}
/**
 * exit_err - print error msg for exit
 * @argv: argument list
 * @com: command
 * @com_count: counter
 * Return: void
 */
void exit_err(char *argv, char *com, int com_count)
{
	char *i, msg[] = ": exit: Illegal number: ";

	i = _itoa(com_count);
	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, com, _strlen(com));
	write(STDERR_FILENO, "\n", 1);
	free(i);
}
/**
 * Exit - exit command
 * @com: command
 * @argv: lest arguments
 * @status: status code
 * @com_count: count of commands
 * Return: void
 */
void Exit(char **com, char **argv, int *status, int com_count)
{
	int _exit = *status;

	if (com[1] && ispos(com[1]))
	{
		_exit = _atoi(com[1]);
	}
	else if (com[1] && !ispos(com[1]))
	{
		exit_err(argv[0], com[1], com_count);
		free_arr(com);
		(*status) = 2;
		return;
	}
	free_arr(com);
	exit(_exit);
}
