#include "shell.h"

/**
 * get_read_line - returns the lines from the stream input
 *
 * Return: the individual elemnts of the string.
 */

char *get_read_line(void)
{
	char bufsize[1024];
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int chr;

	if (!buffer) 
	{
		perror("error: falled to allocate buffer\n");
		exit(EXIT_FAILURE);
	}

	while (true) 
	{
		//read a character
		chr = getchar();

		//if end of file, replace with with a null chr and return
		if (chr == EOF || chr == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = chr;
		}
		position++;

		//if buffer is exceeded, realloc
		if (position >= bufsize)
		{
			bufsize += bufsize;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				perror("error: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
		

