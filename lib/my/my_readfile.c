/*
** EPITECH PROJECT, 2020
** create_config.c
** File description:
** create config of the game
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "libmy.h"

char *my_read_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (65536 + 1));
    char *line = NULL;
    int size = 65536;

    if (buffer == NULL || fd < 0)
        return (NULL);
    while (size > 0) {
        line = my_realloc(line, size);
        size = read(fd, buffer, 65536);
        if ((line == NULL) || (size == -1))
            return (NULL);
        buffer[size] = '\0';
        line = my_strcat(line, buffer);
    }
    if (size == -1)
        return (NULL);
    free(buffer);
    return (line);
}
