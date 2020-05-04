/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strcmp
*/

#include <stddef.h>
#include "libmy.h"

int my_strncmp(char const *str1, char const *str2, int n)
{
    int index = 0;

    if ((str1 == NULL) || (str2 == NULL))
        return (-1);
    while ((index < n) && (str1[index] != '\0') && (str2[index] != '\0') &&
    (str1[index] == str2[index]))
        index++;
    if (index == n)
        return (0);
    return (str1[index] - str2[index]);
}

