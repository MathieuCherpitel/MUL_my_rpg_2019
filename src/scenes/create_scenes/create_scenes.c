/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_scenes
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_rpg.h"
#include "prototype.h"

game_t *call_constructors(game_t *game_data)
{
    int count = 0;
    
    while (count < SCENE_NUMBER) {
        game_data->scenes[count]->constructor(game_data->scenes[count],
                                                game_data->window_data);
        if (game_data->scenes[count] == NULL) {
            write(2, "constructor error\n", 19);
            return (NULL);
        }
        count++;
    }
    return (game_data);
}

scenes_t **allocate_scenes(game_t *game_data)
{
    int count = 0;

    game_data->scenes = malloc(sizeof(scenes_t *) * (SCENE_NUMBER + 1));
    if (game_data->scenes == NULL)
        return (NULL);
    while (count < SCENE_NUMBER) {
        game_data->scenes[count] = malloc(sizeof(scenes_t));
        if (game_data->scenes[count] == NULL)
            return (NULL);
        count++;
    }
    game_data->scenes[count] = NULL;
    return (game_data->scenes);
}

hud_player_t *set_hud(void)
{
    hud_player_t *hud = malloc(sizeof(hud_player_t));

    if (hud == NULL)
        return (NULL);
    hud->hud_sprites = malloc(sizeof(sfSprite *) * 3);
    hud->bar_sprites = malloc(sizeof(sfSprite *) * 8);
    hud->objects_sprites = malloc(sizeof(sfSprite *) * 5);
    hud->active = malloc(sizeof(int *) * 5);
    if (hud->hud_sprites == NULL || hud->bar_sprites == NULL ||
    hud->objects_sprites == NULL || hud->active == NULL)
        return (NULL);
    return (hud);
}

game_t *create_scenes(game_t *game_data)
{
    player_t *player = set_player();

    game_data->scenes = allocate_scenes(game_data);
    if (game_data->scenes == NULL || player == NULL)
        return (NULL);
    for (int count = 0; count < SCENE_NUMBER; count++)
        game_data->scenes[count]->player = player;
    set_function_pointers(game_data);
    game_data = call_constructors(game_data);
    if (game_data == NULL)
        return (NULL);
    return (game_data);
}