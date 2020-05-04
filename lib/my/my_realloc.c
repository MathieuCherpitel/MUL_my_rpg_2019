/*
** EPITECH PROJECT, 2020
** my_realloc.c
** File description:
** realloc an str
*/

#include <stdlib.h>
#include "libmy.h"

char *my_realloc(char *str, int add)
{
    int index = 0;
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * (len + add + 1));

    if (str == NULL) {
        result[0] = '\0';
        return (result);
    }
    while (str[index] != '\0') {
        result[index] = str[index];
        index++;
    }
    result[index] = '\0';
    free(str);
    return (result);
}
