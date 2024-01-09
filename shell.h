#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#define MAX_BUFFER_SIZE 1024
#define MAX_PARAM_SIZE 30

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char **argv, char **env);
void print_console(char *input, const char *prefix);
void manage_special_keys(char *state);
char *_getline(char *input, int buf_size, FILE *stream);
char **split_line_to_array(char *line, char delim);
void executor(char **command, char **env);

char *collect_path(char *file);
int is_path(char *path);
char **get_env_path_array();
char *extract_path_from_bin(char *filename);

#endif /* SIMPLE_SHELL */
