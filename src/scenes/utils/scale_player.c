/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_drawer
*/

#include "prototype.h"
#include "libmy.h"
#include "my_rpg.h"

void scale_sprite(sfSprite **sprites, sfVector2f scale)
{
    for (int i = 0; sprites[i] != NULL; i++)
        sfSprite_scale(sprites[i], scale);
}

int scale_player(loaded_sprites_t **player, int check, sfVector2f scale)
{
    if (check != FALSE)
        return (TRUE);
    for (int i = 0; player[i] != NULL; i++) {
        if ((player[i]->name[0] == 'e') ||
        (player[i]->name[0] == 'k') ||
        (player[i]->name[0] == 'w'))
            scale_sprite(player[i]->sprite, scale);
    }
    return (TRUE);
}

int scale_animated_player(animated_sprites_t *player, int check,
                                                    sfVector2f scale)
{
    if (check != FALSE)
        return (TRUE);
    scale_sprite(player->sprites, scale);
    return (TRUE);
}