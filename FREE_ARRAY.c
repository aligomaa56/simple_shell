#include "main.h"
/**
 * free_arr - free an array
 * @array: array
 * Return: void
 */
void free_arr(char **array)
{
	int i;

	if (!array)
	{
		return;
	};
	for (i = 0; array[i]; i++)
	{
		free(array[i]), array[i] = NULL;
	};
	free(array), array = NULL;
}
