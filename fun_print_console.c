#include "shell.h"
/**
 * manage_special_keys - Manage special key press
 * @state: State of the special key
 * Description: Manage the special keys which are pressed.
 * Return: Nothing yet
 */
void manage_special_keys(char *state)
{
/* If CTRL+D was pressed */
if (state == NULL)
{
exit(0);
}
else if (strncmp(state, "exit", 4) == 0)
{
exit(0);
}
}

/**
 * _getline - Get line from console
 * @input: The buffer which will contain the inputed string.
 * @buf_size: The size of the input buffer.
 * @stream: The stream for listening the character input
 * Description: Prints the console string waiting for input.
 * Return: Nothing
 */
char *_getline(char *input, int buf_size, FILE *stream)
{
int count;
char c;
count = 0;
while (count < buf_size)
{
c = fgetc(stream);
if (c == '\n')
{
break;
}
input[count] = c;
count++;
}
input[count] = '\0';
return (input);
}

/**
 * print_console - Console display
 * @input: The buffer which will contain the inputed string.
 * @prefix: The string to be printed at the start of the console.
 * Description: Prints the console string waiting for input.
 * Return: Nothing
 */
void print_console(char *input, const char *prefix)
{
char *state;
do {
printf("%s", prefix);
state = fgets(input, MAX_BUFFER_SIZE, stdin);
manage_special_keys(state);
} while (input[0] == '\n');
}
