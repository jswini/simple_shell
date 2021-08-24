#include "shell_header.h"
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
		new->file_path = strcat(strdup(str), "/");
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
/*			path = malloc(sizeof(environ[i]));*/
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
/*	free(path);*/

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
