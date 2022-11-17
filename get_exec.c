#include "shell.h"

/**
 * get_exec - exceutes the shell builtins of launch
 * @args: list of args that is null terminated
 *
 * Return: 0 to terminate and 1 for continued
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
