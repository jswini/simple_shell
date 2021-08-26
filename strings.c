#include "shell_header.h"
/**
 * _strlen - determines how long a string is
 * @s: the input string to measure
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int count;

	for (count = 0; *(s + count) != '\0'; count++)
	{}
	return (count);
}
/**
 * str_concat - concatenates two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: pointer to new string, NULL if fails
 */

char *_strcat(char *s1, char *s2)
{
	int size1, size2, i, j;
	char *ptr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (size1 = 0; s1[size1] != 0; size1++)
	{}
	for (size2 = 0; s2[size2] != 0; size2++)
	{}
	ptr = malloc(sizeof(char) * (size1 + size2 + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; s1[i] != 0; i++)
	{
		ptr[i] = s1[i];
	}
	for (j = 0; s2[j] != 0; j++)
	{
		ptr[i] = s2[j];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
/**
 * _strdup - copies string to allocated memory
 * @str: pointer to a string
 *
 * Return: pointer to copied string, NULL if str is NULL or malloc error
 */

char *_strdup(const char *str)
{
	int size, i;
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (size = 0; str[size] != 0; size++)
	{}
	size++;
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '/';
	i++;
	ptr[i] = '\0';
	return (ptr);
}

/**
 * _strcmp - compares 2 strings
 * @s1: pointer to 1st string
 * @s2: pointer to 2nd string
 *
 * Return: difference between s1 and s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}

	return (s1[i] - s2[i]);
}

/**
 * _strncmp - compares n characters of 2 strings
 * @s1: pointer to 1st string
 * @s2: pointer to 2nd string
 * @n: number of character to check
 *
 * Return: difference between the nth character
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
		if (i + 1 == n)
			break;
	}

	return (s1[i] - s2[i]);
}
