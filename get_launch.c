#include "shell.h"

/**
 * get_launch - lauchs a program and waits for it to terminate
 * @args: list of arguments
 *
 * Return: 1 for continued executuion
 */

int get_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		/*hild process*/
		if (execvp(args[0], args) == -1)
		{
			perror("error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/*rror forking*/
		perror("error");
	}
	else
	{
		/* Parent process*/
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
