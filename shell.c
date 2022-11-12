#include "shell.h"

/**
 * main - a simple UNIX command line interpreter
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0.
*/
int main(int ac, char **av)
{
	while (true)
	{
		char *start = "| ";
		char *line;

		(void)ac; (void)av

		printf("%s", start);
		getline(&line, &n, stdin);
		printf("%s\n, line");
		free(line);
	}

}	return (0);
