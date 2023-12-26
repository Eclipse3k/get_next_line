#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    char *line = malloc(sizeof(char));
    if (!line)
        return NULL;
    return read_from_fd(fd, buffer, line);
}
/*
int main()
{
    int fd;
	char *buffer;
    
    #include <fcntl.h>

    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening the file");
    }
    while (buffer = get_next_line(fd))
	    printf("%s", buffer);
}*/