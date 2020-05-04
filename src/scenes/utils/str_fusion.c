/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** str fusion
*/


#include <stdlib.h>
#include "prototype.h"
#include "libmy.h"

char *str_fusion(char *str1, char *str2)
{
    int index = 0;
    int len = my_strlen(str1) + my_strlen(str2);
    char *result = malloc(sizeof(char) * (len + 1));

    for (int i = 0; str1[i] != '\0'; i++) {
        result[index] = str1[i];
        index++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        result[index] = str2[i];
        index++;
    }
    result[index] = '\0';
    return (result);
}