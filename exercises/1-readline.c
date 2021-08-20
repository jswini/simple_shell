#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *buffer;
	size_t buffer_length = 32;
	ssize_t num_of_char;

	printf("$ ");
	buffer = malloc(sizeof(char) * buffer_length);
	if (!buffer)
		return (-1);
	num_of_char = getline(&buffer, &buffer_length, stdin);
	if (num_of_char < 0)
		return (-1);
	printf("%s", buffer);
	return (0);
}
