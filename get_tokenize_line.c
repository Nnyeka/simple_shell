#include "shell.h"
#define BUFSIZE 64
/**
 * get_tokenize_line: to split a line to tokens
 * @line: the line to be splitted.
 * 
 * Return: array of tokens with null terminator
 */

char **get_tokenize_line(char *line)
{
	int bufsize = BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;
	const char *delim = " ";
	
	if (!tokens)
	{
		perror("error: allocation error\n");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		
		if (position >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			
			if (!tokens)
			{
				perror("error: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	
	tokens[position] = NULL;
	return tokens;
}
