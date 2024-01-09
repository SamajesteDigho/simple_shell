#include "shell.h"
/**
 * collect_path
 * @file: The name of the file to execute or the file path
 * Description: Permits to get the file to be executed path
 * Return: String of the file path if file found or NULL otherwise.
 */
char *collect_path(char *file)
{
char *tmp;
if (file == NULL || file[0] == '\n')
{
return (NULL);
}
if (is_path(file) == 1)
{
return (file);
}
else
{
tmp = (char *) malloc(MAX_BUFFER_SIZE * sizeof(char));
tmp = strcat(tmp, "./");
tmp = strcat(tmp, file);
if (access(tmp, X_OK) == 0)
{
return (tmp);
}
free(tmp);
return (extract_path_from_bin(file));
}
}

/**
 * is_path
 * @path: The path to be checked
 * Description: Check if a string is a file or a path
 * Return: 0 = false or 1 = true
 */
int is_path(char *path)
{
int i;
int is_path;
is_path = 0;
i = 0;
while (path[i] != '\0' && path[i] != '\n')
{
if (path[i] == '/')
{
is_path = 1;
break;
}
i++;
}
return (is_path);
}

/**
 * get_env_path
 * Description: Permits to get the array of environment source paths
 * Return: Array of environment paths
 */
char **get_env_path_array()
{
char **paths;
paths = split_line_to_array(getenv("PATH"), ':');
return (paths);
}

/**
 * extract_path_from_bin
 * @filename: The file to be found
 * Description: Permits to get the array of environment source paths
 * Return: The path of the given filename if found or NULL otherwise
 */
char *extract_path_from_bin(char *filename)
{
char **paths;
char *path;
int i;
unsigned long size;
paths = get_env_path_array();
path = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
size = sizeof(path);
i = 0;
while (paths[i] != NULL)
{
path = paths[i];
i++;
path = strcat(path, "/");
path = strcat(path, filename);
if (access(path, X_OK) == 0)
{
return (path);
}
memset(path, 0, size);
}
return (NULL);
}
