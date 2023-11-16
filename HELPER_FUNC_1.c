#include "main.h"
/**
 * _strlen - calc len
 * @str: string
 * Return: len
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	return (i);
}
/**
 * _strcat - connects two str
 * @dest: first one
 * @src: second one
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int j = 0;

	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[j] != '\0')
	{
		dest[len + j] = src[j];
		j++;
	}
	dest[len + j] = '\0';
	return (dest);
}
/**
 * *_strcpy - copies string
 * @dest: string copy to
 * @src: string copy from
 * Return: pointer to str
 */
char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_start);
}
/**
 * _strdup - Duplicate str
 * @str: string
 * Return: string, or NULL
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}
/**
 * _strcmp - Compare two strings
 * @s1: first one
 * @s2: second one
 * Return: strings
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int x = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			x = s1[i] - s2[i];
			break;
		}
	}
	return (x);
}
