#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char *read_from_fd(int fd, char *buffer, char *line)
{
    int i = 0;
    char c;
    while (read(fd, &c, 1) > 0)
    {
        buffer[i++] = c;
        if (c == '\n' || i == BUFFER_SIZE)
        {
            line = allocate_line(buffer, i);
            return line;
        }
    }
    if (i == 0)
    {
        free(line);
        return NULL;
    }
    line = allocate_line(buffer, i);
    return line;
}

char *allocate_line(char *buffer, int i)
{
    int j = 0;
    char *line = malloc((i + 1) * sizeof(char));
    if (!line)
        return NULL;
    while (j < i)
    {
        line[j] = buffer[j];
        j++;
    }
    line[j] = '\0';
    return line;
}