#define MAX_BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * get_env_value - Getting env value given name
 * @name: The name of the variable to be collected.
 * Description: Permits to collect the value of the env vars given the name.
 * Return: The vlue of the variable if it exist and NULL otherwise.
 */
char *get_env_value(const char *name)
{
int pos, i, name_size, similar;
char *cursor, *value, *bushi;
bushi = "";
if (name == NULL || name == bushi)
{
return (NULL);
}
pos = similar = name_size = 0;
cursor = __environ[pos];
while (cursor)
{
i = 0;
while (name[i] != '\0' && name[i] != '\n' && name[i] != '=')
{
if (name[i] == cursor[i])
{
similar = 1;
name_size = i;
}
else
{
similar = 0;
break;
}
i++;
}
if (similar == 1)
{
break;
}
cursor = __environ[pos++];
}
if (similar == 1)
{
value = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
name_size = name_size + 2;
i = name_size;
while (cursor[i] != '\0' && cursor[i] != '\n' && i < 1024)
{
value[i - name_size] = cursor[i];
i++;
}
cursor[i] = '\0';
return (value);
}
return (NULL);
}
/**
 * print_environment - Print the env variables
 * Description: Here is the main source file for entring the program
 * Return: Always returns 0
 */
int print_environment(void)
{
printf("USER=%s\n", get_env_value("USER"));
printf("LANGUAGE=%s\n", get_env_value("LANGUAGE"));
printf("SESSION=%s\n", get_env_value("SESSION"));
printf("COMPIZ_CONFIG_PROFILE=%s\n", get_env_value("COMPIZ_CONFIG_PROFILE"));
printf("SHLVL=%s\n", get_env_value("SHLVL"));
printf("HOME=%s\n", get_env_value("HOME"));
printf("C_IS=%s\n", get_env_value("C_IS"));
printf("DESKTOP_SESSION=%s\n", get_env_value("DESKTOP_SESSION"));
printf("LOGNAME=%s\n", get_env_value("LOGNAME"));
printf("TERM=%s\n", get_env_value("TERM"));
printf("PATH=%s\n", get_env_value("PATH"));
printf("DISPLAY=%s\n", get_env_value("DISPLAY"));
return (0);
}

/**
 * main - Entry point
 * Description: Here is the main source file for entring the program
 * Return: Always returns 0
 */
int main(void)
{
print_environment();
return (0);
}
