#include "shell_header.h"
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
 * add_node_end - adds a node to the end of a singly linked list
 * @head: pointer to the list
 * @str: string to store in the new node
 *
 * Return: pointer to new node
 */

paths *add_node_end(paths **head, const char *str)
{
	paths *new, *last;

	new = malloc(sizeof(paths));
	if (!new)
		return (NULL);
	if (!str)
	{
		new->file_path = NULL;
	}
	else
	{
		new->file_path = _strdup(str);
		if (!new->file_path)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		last = (paths *)*head;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new;
	}
	return (new);
}

paths *get_path(void)
{
	int i;
	char *path, *path_tok;
	paths *path_list = NULL;
	char delim[] = {':', '=', '\n'};

	for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], "PATH", 4) == 0)
        {
			path = environ[i];
			break;
		}
	}
	path_tok = strtok(path, delim);
	path_tok = strtok(NULL, delim);
	while (path_tok)
	{
		add_node_end(&path_list, path_tok);
		path_tok = strtok(NULL, delim);
	}

	return (path_list);
}
/**
 * free_list - frees memory allocated for a singly linked list
 *
 * @head: pointer to the list to free
 */

void free_list(paths *head)
{
	paths *ptr = head;

	if (!head)
		return;
	free_list(head->next);
	free(ptr->file_path);
	free(ptr);
}
/**
 * print_list - prints all elements of a singly linked list
 * @h: pointer to start of list
 *
 * Return: number of nodes
 */
size_t print_list(const paths *h)
{
	size_t nodes = 0;
	paths *ptr = (paths *)h;

	if (!h)
		return (0);

	while (ptr)
	{
		if (!ptr->file_path)
			printf("(nil)\n");
		else
			printf("%s\n", ptr->file_path);
		nodes++;
		ptr = ptr->next;
	}
	return (nodes);
}
/*int main(void)
{
	paths *path = NULL;

	path = get_path();
	print_list(path);
	free_list(path);
	return (0);
}*/
