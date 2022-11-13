#ifndef SHELL_H
#define SHELL_H

/* import Standard Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>


/* PROTOTYPES */
int _putchar(char);
char *get_read_line(void);
char **get_split_line(char *line);
int get_exec(char **args);
int get_launch(char **args);

/* Function Declarations for builtin shell commands:*/
int get_exit(char **args);
int get_help(char **args);
int get_cd(cahr **args);

#endif
