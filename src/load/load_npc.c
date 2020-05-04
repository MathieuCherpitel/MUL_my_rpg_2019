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

sfSprite **load_npc_sprites_sheet(sfTexture *texture)
{
    int index = 0;
    sfVector2f scale = {.x = 1.5, .y = 1.5};
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 10);
    sfIntRect rect = {0, 0, 16, 28};
    int nb_sprite = 4;

    for (int i = 0; i < 3; i++) {
        for (int c = 0; c < nb_sprite; c++) {
            sprite[index] = sfSprite_create();
            sfSprite_setTexture(sprite[index], texture, sfTrue);
            sfSprite_setTextureRect(sprite[index], rect);
            sfSprite_setScale(sprite[index], scale);
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

loaded_sprites_t **load_npc_loop(char **assets_path,
                                        loaded_sprites_t **players)
{
    int count = 0;

    while (count < 2) {
        players[count] = malloc(sizeof(loaded_sprites_t));
        if (players[count] == NULL)
            return (NULL);
        players[count]->sprite = malloc(sizeof(sfSprite *) * 
                                                (PLAYER_SPRITE_COUNT));
        if (players[count]->sprite == NULL)
            return (NULL);
        players[count]->name = get_asset_name(assets_path[count]);
        players[count]->texture = sfTexture_createFromFile
                                                (assets_path[count], NULL);
        players[count]->sprite = load_npc_sprites_sheet
                                                (players[count]->texture);
        count++;      
    }
    players[count] = NULL;
    return (players);
}

loaded_sprites_t **load_npc(char **assets_path, loaded_sprites_t **players)
{
    int assets_count = get_tab_len(assets_path);

    players = malloc(sizeof(loaded_sprites_t *) *(assets_count + 1));
    if (players == NULL)
        return (NULL);
    players = load_npc_loop(assets_path, players);
    if (players == NULL)
        return (NULL);
    return (players);
}
