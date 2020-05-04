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

loaded_sprites_t **load_player_loop(char **assets_path,
                                            loaded_sprites_t **players)
{
    int count = 0;

    while (count < PLAYER_SPRITE_COUNT) {
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
        players[count]->sprite = load_player_sprites(players[count]);
        count++;      
    }
    players[count] = NULL;
    return (players);
}

loaded_sprites_t **load_players(char **assets_path, loaded_sprites_t **players)
{
    int assets_count = get_tab_len(assets_path);

    players = malloc(sizeof(loaded_sprites_t *) *(assets_count + 1));
    if (players == NULL)
        return (NULL);
    players = load_player_loop(assets_path, players);
    if (players == NULL)
        return (NULL);
    return (players);
}
