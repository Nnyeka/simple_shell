#include "shell.h"

/**
 * lsh_num_builtins - to return the builtins
 *
 * Return: the builtins
 */

int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * get_cd -change dir
 * @args: arguments
 * Return: to return 1
 */

int get_cd(char **args)
{
	if (args[1] == NULL)
	{
		perror("error: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error");
		}
	}
	return (1);
}

/**
 * get_help - get help
 * @args: arguments
 * Return: to return 1 to continue
 */

int get_help(char **args)
{
	int i;

	printf("the help section\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}
	printf("Use the man command to get information.\n");
	return (1);
}

/**
 * get_exit - to exit
 * @args: arguments
 * Return: to return 1
 */

int get_exit(char **args)
{
	return (0);
}

/**
 * get_exec - exceutes the shell builtins of launch
 * @args: list of args that is null terminated
 * Return: 0 to terminate else 1
 */

int get_exec(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		/*An empty command*/
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (get_launch(args));
}
