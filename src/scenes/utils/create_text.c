/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_text
*/

#include "prototype.h"

sfText *move_text(sfText *text, int x, int y)
{
    sfVector2f pos = {.x = x, .y = y};

    sfText_setPosition(text, pos);
    return (text);
}

sfText *create_text(sfFont *font, char *string, sfColor color, int size)
{
    sfText *text = sfText_create();

    if (text == NULL)
        return (NULL);
    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    return (text);
}