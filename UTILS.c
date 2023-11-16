#include "main.h"
/**
 * revstr - rev string
 * @str: str
 * @len: length
 * Return: void
 */
void revstr(char *str, int len)
{
	char x;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		x = str[start];
		str[start] = str[end];
		str[end] = x;
		start++;
		end--;
	}
}
/**
 * ispos - checks num positive
 * @str: string
 * Return: 0 if positive or 1 if negative
 */
int ispos(char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
