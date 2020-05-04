/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** place_scale_spites
*/

#include "my_rpg.h"
#include "prototype.h"

void place_scale_sprite_sheet(sfSprite **sprites, sfVector2f pos,
                                                    sfVector2f scale)
{
    int count = 0;

    while (sprites[count] != NULL) {
        sfSprite_setPosition(sprites[count], pos);
        sfSprite_scale(sprites[count], scale);
        count++;
    }
}