#include "shell_header.h"
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
paths *path_list()
{
	int i;
	char *path, *path_tok;
	paths *path_list = NULL;
	char delim[] = {':', '=', '\n'};

	for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], "PATH", 4) == 0)
        {
			path = malloc(sizeof(environ[i]));
			path = environ[i];
		}
	}
	path_tok = strtok(path, delim);
	while (path_tok)
	{
		path_tok = strtok(NULL, delim);
		add_node(&path_list, path_tok);
	}
	print_list(path_list);

	return (path_list);
}
int main(void)
{
	path_list();
	return (0);
}
