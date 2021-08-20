#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char *buffer;
	size_t buffer_length = 32;
	ssize_t num_of_char;
	char *token;
	char **ar_token;
	char delim[] = {' ', '\n', '\t', ',', '/', '.'};
	int index = 0;
	int i = 0;

	printf("$ ");
	buffer = malloc(sizeof(char) * buffer_length);
	if (!buffer)
		return (-1);
	num_of_char = getline(&buffer, &buffer_length, stdin);
	if (num_of_char < 0)
		return (-1);
	ar_token = malloc(sizeof(buffer));
       	token = strtok(buffer, delim);
	ar_token[index] = token;
	index++;
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		ar_token[index] = token;
		index++;
	}
	while (ar_token[i] != NULL)
	{
		printf("%s\n", ar_token[i]);
		i++;
	}
	free(ar_token);
	free(buffer);
	return (0);
}
