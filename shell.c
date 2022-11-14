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
	/*run while loop in main entry point*/
	while (true)
	{
		char *start = "$ ";
		char *line;
		char **args;

		(void)ac; (void)av;

		printf("%s", start);
		line = get_read_line();
		args = get_tokenize_line(line);
		
		if (args[0] != NULL)
		{
			get_exec(args);
		}

		free(line);
		free(args);

		return (0);
	}
}
