/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** allocate_obj
*/

#include <stdlib.h>
#include "prototype.h"

object_t **allocate_obj(int obj_count)
{
    int count = 0;
    object_t **arr = malloc(sizeof(object_t *) * (obj_count + 1));

    if (arr == NULL)
        return (NULL);
    while (count < obj_count) {
        arr[count] = malloc(sizeof(object_t));
        if (arr[count] == NULL)
            return (NULL);
        count++;
    }
    arr[count] = NULL;
    return (arr);
}
