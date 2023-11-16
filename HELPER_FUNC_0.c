#include "main.h"
/**
 * _itoa - int to str
 * @num: int
 * Return: str
 */
char *_itoa(int num)
{
	char buf[25];
	int i = 0;

	if (num == 0)
		buf[i++] = '0';
	else
	{
		while (num > 0)
		{
			buf[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buf[i] = '\0';
	revstr(buf, i);

	return (_strdup(buf));
}
/**
 * _atoi - str to int
 * @str: string
 * Return: integer
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return (num);
}
