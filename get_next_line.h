#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#define BUFFER_SIZE 1024

char *get_next_line(int fd);
char *read_from_fd(int fd, char *buffer, char *line);
char *allocate_line(char *buffer, int i);

#endif
