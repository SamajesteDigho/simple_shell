#include "shell.h"
/**
 * main - Entry point
 * @argc: Number of parameters passed
 * @argv: Array containing the list of parameters
 * @env: Array containing the environment variables
 * Description: Here is the main source file for entring the program
 * Return: Always returns 0
 */
int main(int argc, char **argv, char **env)
{
char *input;
char *prefix;
char **commands;
if (argc > 1)
{
prefix = argv[1];
strcat(prefix, "$ ");
}
else
{
prefix = "($) ";
}
input = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
while (1 == 1)
{
print_console(input, prefix);
commands = split_line_to_array(input, ' ');
executor(commands, env);
memset(input, 0, MAX_BUFFER_SIZE);
}
return (0);
}
