/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** enemies_trigger
*/

#include "prototype.h"
#include "my_rpg.h"

void check_trigger(window_t *window_data, scenes_t *scene, enemy_t *enemy)
{
    if (window_data->current_enemy->status == ALIVE) {
        window_data->current_scene = FIGHT;
        scene->music_start = FALSE;
        sfMusic_pause(scene->music);
    }
    else
        enemy->status = DEAD;
}

void last_enemy_trigger(scenes_t *scene, window_t *window_data,
                                                            char **grid)
{
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'G') {
        window_data->current_enemy = window_data->enemies[9];
        check_trigger(window_data, scene, scene->game_objects->enemies[9]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'z') {
        window_data->current_enemy = window_data->enemies[8];
        check_trigger(window_data, scene, scene->game_objects->enemies[10]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'D') {
        window_data->current_enemy = window_data->enemies[0];
        check_trigger(window_data, scene, scene->game_objects->enemies[11]);
    }
}

void even_more_enemy_trigger(scenes_t *scene, window_t *window_data,
                                                                char **grid)
{
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'Z') {
        window_data->current_enemy = window_data->enemies[1];
        check_trigger(window_data, scene, scene->game_objects->enemies[6]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'a') {
        window_data->current_enemy = window_data->enemies[13];
        check_trigger(window_data, scene, scene->game_objects->enemies[7]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'Y') {
        window_data->current_enemy = window_data->enemies[5];
        check_trigger(window_data, scene, scene->game_objects->enemies[8]);
    }
    last_enemy_trigger(scene, window_data, grid);
}

void more_enemy_trigger(scenes_t *scene, window_t *window_data, char **grid)
{
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'M') {
        window_data->current_enemy = window_data->enemies[11];
        check_trigger(window_data, scene, scene->game_objects->enemies[3]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 's') {
        window_data->current_enemy = window_data->enemies[7];
        check_trigger(window_data, scene, scene->game_objects->enemies[4]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'S') {
        window_data->current_enemy = window_data->enemies[12];
        check_trigger(window_data, scene, scene->game_objects->enemies[5]);
    }
    even_more_enemy_trigger(scene, window_data, grid);
}

void enemy_trigger(scenes_t *scene, window_t *window_data, char **grid)
{
    check_other_trigger(scene, grid);
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'g') {
        window_data->current_enemy = window_data->enemies[3];
        check_trigger(window_data, scene, scene->game_objects->enemies[0]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'I') {
        window_data->current_enemy = window_data->enemies[4];
        check_trigger(window_data, scene, scene->game_objects->enemies[1]);
    }
    if (grid[(int)scene->pos.y][(int)scene->pos.x] == 'b') {
        window_data->current_enemy = window_data->enemies[6];
        check_trigger(window_data, scene, scene->game_objects->enemies[2]);
    }
    more_enemy_trigger(scene, window_data, grid);
}