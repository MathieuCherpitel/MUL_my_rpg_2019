/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_scene_constructor
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"
#include "prototype.h"

static scenes_t *allocate_scene(scenes_t *scene)
{
    int text_count = 2;

    scene->text = malloc(sizeof(sfText *) * (text_count + 1));
    scene->buttons = NULL;
    scene->game_objects = NULL;
    if (scene->text == NULL)
        return (NULL);
    return (scene);
}

static sfText **set_text(scenes_t *scene, window_t *window_data)
{
    scene->text[0] = create_text(window_data->fonts[RALEWAY],
                                "Press any key to begin", sfWhite, 30);
    scene->text[0] = move_text(scene->text[0], 790, 940);
    scene->text[1] = create_text(window_data->fonts[CORONOS],
                                            "Path of Fate", sfWhite, 80);
    scene->text[1] = move_text(scene->text[1], 750, 160);
    scene->text[2] = NULL;
    return (scene->text);
}

game_objects_t *create_game_obj(scenes_t *scene, window_t *window_data)
{
    scene->game_objects = malloc(sizeof(game_objects_t));
    if (scene->game_objects == NULL)
        return (NULL);
    scene->game_objects->enemies = NULL;
    scene->game_objects->npc = NULL;
    scene->game_objects->sounds = NULL;
    scene->game_objects->objects = create_loading_obj(scene, window_data);
    if (scene->game_objects->objects == NULL)
        return (NULL);
    return (scene->game_objects);
}

scenes_t *loading_constructor(scenes_t *scene, window_t *window_data)
{
    scene = allocate_scene(scene);
    if (scene == NULL)
        return (NULL);
    scene->game_objects = create_game_obj(scene, window_data);
    if (scene->game_objects == NULL)
        return (NULL);
    scene->background = get_background_asset("loading_backgrond_v4.png",
                                    window_data->loaded_assets->background);
    sfSprite_scale(scene->background, (sfVector2f){1.44, 1.44});
    scene->music = window_data->musics[CELESTIAL];
    scene->text = set_text(scene, window_data);
    return (scene);
}