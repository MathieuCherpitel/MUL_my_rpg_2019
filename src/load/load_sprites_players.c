/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_players
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"
#include "prototype.h"

sfSprite **load_sprite_enemy_hud(sfTexture *texture, int scale)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 6);
    sfIntRect rect = {.left = 0, .top = 0, .width = 125, .height = 67};
    sfIntRect rect_bar = {.left = 0, .top = 67, .width = 100, .height = 10};

    for (int index = 0; index < 5; index++) {
        sprite[index] = sfSprite_create();
        sfSprite_setTexture(sprite[index], texture, sfTrue);
        sfSprite_setTextureRect(sprite[index], rect);
        sfSprite_scale(sprite[index], (sfVector2f){.x = scale, .y = scale});
        rect.top += 10;
        rect = (index == 0) ? rect_bar : rect;
    }
    sprite[5] = NULL;
    return (sprite);
}

sfSprite **load_sprite_player_hud(sfTexture *texture, int scale)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 9);
    sfIntRect rect = {.left = 0, .top = 0, .width = 184, .height = 67};
    sfIntRect rect_bar = {.left = 0, .top = 67, .width = 100, .height = 10};

    for (int index = 0; index < 8; index++) {
        sprite[index] = sfSprite_create();
        sfSprite_setTexture(sprite[index], texture, sfTrue);
        sfSprite_setTextureRect(sprite[index], rect);
        sfSprite_scale(sprite[index], (sfVector2f){.x = scale, .y = scale});
        rect.top += 10;
        rect = (index == 0) ? rect_bar : rect;
    }
    sprite[8] = NULL;
    return (sprite);
}

sfSprite **load_player_icon_sprite_sheet(sfTexture *texture, int scale)
{
    int index = 0;
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 7);
    sfIntRect rect = {0, 0, 52, 52};
    int nb_sprite = 6;

    while (index < nb_sprite) {
        sprite[index] = sfSprite_create();
        sfSprite_setTexture(sprite[index], texture, sfTrue);
        sfSprite_setTextureRect(sprite[index], rect);
        sfSprite_scale(sprite[index], (sfVector2f){.x = scale, .y = scale});
        rect.left += 52;
        index++;
    }
    sprite[index] = NULL;
    return (sprite);
}

sfSprite **load_player_sprite_sheet(sfTexture *texture)
{
    int index = 0;
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 10);
    sfIntRect rect = {0, 0, 16, 28};
    int nb_sprite = 4;

    for (int i = 0; i < 3; i++) {
        for (int c = 0; c < nb_sprite; c++) {
            sprite[index] = sfSprite_create();
            sfSprite_setTexture(sprite[index], texture, sfTrue);
            sfSprite_setTextureRect(sprite[index], rect);
            rect.left += 16;
            index++;
        }
        nb_sprite = (i == 1) ? 1 : nb_sprite;
        rect.top += 28;
        rect.left = 0;
    }
    sprite[index] = NULL;
    return (sprite);
}

sfSprite **load_player_sprites(loaded_sprites_t *players)
{
    int scale = 3.5;

    if (my_strcmp(players->name, "icon_player.png") == 0)
        return (load_player_icon_sprite_sheet(players->texture, scale));
    if (my_strcmp(players->name, "hud.png") == 0)
        return (load_sprite_player_hud(players->texture, scale));
    if (my_strcmp(players->name, "hud_enemy.png") == 0)
        return (load_sprite_enemy_hud(players->texture, scale));
    return (load_player_sprite_sheet(players->texture));
}