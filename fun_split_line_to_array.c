#include "shell.h"
/**
 * split_line_to_array
 * @line: The line to split
 * @delim: The delimiter character
 * Description: This functions splits the line to words
 * Return: Array of words
 */
char **split_line_to_array(char *line, char delim)
{
char **words;
char *word;
char c;
int pos;
int start;
int end;
int i;
int nbwords;
nbwords = 0;
words = (char **)malloc(MAX_PARAM_SIZE * sizeof(char *));
c = ' ';
pos = 0;
while (c != '\0' && c != '\n')
{
c = line[pos];
start = pos;
end = pos;
while (c != delim && c != '\0' && c != '\n')
{
pos = pos + 1;
c = line[pos];
end = pos;
}
if (start < end)
{
word = (char *)malloc((end - start) *sizeof(char));
for (i = start; i < end; i++)
{
word[i - start] = line[i];
}
words[nbwords] = word;
nbwords = nbwords + 1;
}
pos = pos + 1;
}
words[nbwords] = NULL;
return (words);
}
