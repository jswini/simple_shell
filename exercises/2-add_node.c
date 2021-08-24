#include "shell_header.h"
/**
 * add_node - adds a node to a singly linked list
 * @head: pointer to the list
 * @str: string to store in the new node
 *
 * Return: address of new node, NULL upon failure
 */
paths *add_node(paths **head, const char *str)
{
	paths *new;

	new = malloc(sizeof(paths));
	if (!new)
		return (NULL);
	if (!*head)
		new->next = NULL;
	else
		new->next = *head;
	if (!str)
	{
		new->file_path = NULL;
	}
	else
	{
		new->file_path = strdup(str);
		if (!new->file_path)
		{
			free(new);
			return (NULL);
		}
	}
	*head = new;
	return (*head);
}
