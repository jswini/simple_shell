#include <unistd.h>
#include <stdio.h>
int main (__attribute__((unused))int argc, __attribute__((unused))char **argv, char **env)
{
	extern char **environ;
	/*int i;*/

	printf("%p\n", *environ);
	printf("%p\n", *env);
	return (0);
}