#include "shell.h"
/**
 * lsh_num_builtins - returns builtins
 */

char *builtin_str[] = 
{
	 "cd",
	 "help",
	 "exit"
};

int (*builtin_func[]) (char **) = 
{
       	&get_cd,
	&get_help,
	&get_exit
};

int lsh_num_builtins() 
{
	return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/

/**
   get_cd - change directory.
   @args: List of args.  args[0] is "cd".  args[1] is the directory.
   @Return: Always returns 1, to continue executing.
 */
int get_cd(char **args)
{
	if (args[1] == NULL) 
	{
		perror(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error");
		}
	}
	return 1;
}

/**
   get_help - prints help
   @args: List of args.  Not examined.
   @Return: Always returns 1, to continue executing.
 */
int get_help(char **args)
{
       	int i;

	printf("what is the problem?\n")
		
	
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return 1;
}

/**
   get_exit - to exit
   @args: arguments
   @Return: Always returns 0, to terminate execution.
 */
int get_exit(char **args)
{
	return 0;
}
