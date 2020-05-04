/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** places_constructors
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "libmy.h"
#include "prototype.h"

void set_dungeon_data(scenes_t *scene, window_t *window_data)
{
    scene->view = sfView_create();
    scene->game_objects = dungeon_game_object(scene, window_data);
    scene->buttons = NULL;
    scene->background = get_background_asset("dungeon.png",
    window_data->loaded_assets->background);
    scene->music = window_data->musics[NOCTURIAL];
    scene->text = NULL;
    scene->pointers = malloc(8 * 3);
    scene->pos = (sfVector2f){.x = DUNGEON_X, .y = DUNGEON_Y};

}

scenes_t *dungeon_constructor(scenes_t *scene, window_t *window_data)
{
    char *file_buf = my_read_file("rpg_assets/backgrounds/dungeon.evt");
    if (!file_buf)
        return NULL;
    set_dungeon_data(scene, window_data);
    if (!scene->pointers)
        return NULL;
    scene->GRID = my_str_to_word_array(file_buf, "\n");
    if (!scene->GRID)
        return NULL;
    scene->WORLD_PTR_MAX = NULL;
    sfView_setSize(scene->view, (sfVector2f){.x = 1920, .y = 1080});
    sfView_setCenter(scene->view, (sfVector2f){.x = (DUNGEON_X * 24) + 12,
                                            .y = (DUNGEON_Y * 24) + 12});
    sfView_zoom(scene->view, 0.5);
    free(file_buf);
    window_data->dungeon_ptr = scene;
    return (scene);
}

void set_house_data(scenes_t *scene, window_t *window_data)
{
    scene->view = sfView_create();
    scene->game_objects = NULL;
    scene->buttons = NULL;
    scene->background = get_background_asset("player_house.png",
    window_data->loaded_assets->background);
    scene->music = window_data->musics[NOCTURIAL];
    scene->text = NULL;
    scene->pos = (sfVector2f){.x = 7, .y = 10};
    scene->pointers = malloc(8 * 3);
}

scenes_t *house_constructor(scenes_t *scene, window_t *window_data)
{
    char *file_buf = my_read_file("rpg_assets/backgrounds/player_house.evt");

    if (!file_buf)
        return NULL;
    set_house_data(scene, window_data);
    if (!scene->pointers)
        return NULL;
    scene->GRID = my_str_to_word_array(file_buf, "\n");
    if (!scene->GRID)
        return NULL;
    scene->WORLD_PTR_MAX = NULL;
    sfView_setSize(scene->view, (sfVector2f){.x = 1920, .y = 1080});
    sfView_setCenter(scene->view, (sfVector2f){.x = (7 * 24) + 12,
                                                        .y = (10 * 24) + 12});
    sfView_zoom(scene->view, 0.5);
    free(file_buf);
    return (scene);
}