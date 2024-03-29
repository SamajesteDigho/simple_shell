#include "shell.h"
/**
 * executor - The executor function
 * @command: Array containing the command and its parameters
 * @env: Array containing the env variables
 * Description: Execute a given process or file.
 * Return: void
 */
void executor(char **command, char **env)
{
char *path;
char process;
int status;
path = collect_path(command[0]);
if (path != NULL)
{
process = fork();
if (process != -1 && process == 0)
{
if (execve(path, command, env) == -1)
{
perror(command[0]);
exit(98);
}
exit(0);
}
wait(&status);
}
/*else
{
perror("command[0]");
}*/
}
