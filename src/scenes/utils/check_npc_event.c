/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** world_input
*/

#include "prototype.h"
#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

void check_npc_world_event
(scenes_t *scene, window_t *window_data, char **grid, int index)
{
    int count;
    char c[] = "Nno";

    if (window_data->current_scene != WORLD)
        return;
    if ((scene->game_objects->npc[index]->active == TRUE) &&
    (grid[(int)scene->pos.y][(int)scene->pos.x] != c[index])) {
        count = scene->game_objects->npc[index]->current_dialog;
        scene->game_objects->npc[index]->current_dialog =
        (count < 2) ? count + 1 : 0;
    }
    scene->game_objects->npc[index]->active = FALSE;
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == c[index])
        scene->game_objects->npc[index]->active = TRUE;
}

void check_npc_dungeon_event
(scenes_t *scene, window_t *window_data, char **grid)
{
    int count;

    if (window_data->current_scene != DUNGEON)
        return;
    if ((scene->game_objects->npc[0]->active == TRUE) &&
    (grid[(int)scene->pos.y][(int)scene->pos.x] != 'H')) {
        count = scene->game_objects->npc[0]->current_dialog;
        scene->game_objects->npc[0]->current_dialog =
        (count < 2) ? count + 1 : 0;
    }
    scene->game_objects->npc[0]->active = FALSE;
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'H')
        scene->game_objects->npc[0]->active = TRUE;
}