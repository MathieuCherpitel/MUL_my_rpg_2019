/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strcmp
*/

#include <stddef.h>
#include "libmy.h"

int my_strcmp(char *str1, char *str2)
{
    int index = 0;

    if ((str1 == NULL) || (str2 == NULL))
        return (0);
    while ((str1[index] != '\0') && (str2[index] != '\0') &&
        (str1[index] == str2[index]))
        index++;
    return (str1[index] - str2[index]);
}

