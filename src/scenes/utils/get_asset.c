/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_asset
*/

#include "prototype.h"
#include "libmy.h"

sfSprite *get_background_asset(char *name, loaded_sprites_t **background)
{
    int count = 0;

    while (my_strcmp(name, background[count]->name) != 0)
        count++;
    return (background[count]->sprite[0]);
}

sfSprite *get_any_asset(char *name, loaded_sprites_t **category)
{
    int count = 0;

    while (my_strcmp(name, category[count]->name) != 0)
        count++;
    return (category[count]->sprite[0]);
}

sfSprite **get_sprite_asset(char *name, loaded_sprites_t **category)
{
    int count = 0;

    while (my_strcmp(name, category[count]->name) != 0)
        count++;
    return (category[count]->sprite);
}