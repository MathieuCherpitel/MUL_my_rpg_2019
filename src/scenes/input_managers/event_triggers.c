/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_triggers
*/

#include "prototype.h"
#include "my_rpg.h"

void check_open_door(scenes_t *scene, char** grid)
{
    if (scene->player->hud->active[2] == TRUE) {
        if ((grid[(int)scene->pos.y][(int)scene->pos.x] == 'K'
                        && sfKeyboard_isKeyPressed(sfKeyF) == sfTrue))
            move(scene, scene->view, -2, 0);
        if ((grid[(int)scene->pos.y][(int)scene->pos.x] == 'k'
                        && sfKeyboard_isKeyPressed(sfKeyF) == sfTrue))
            move(scene, scene->view, 4, 0);
    }
}

void check_other_trigger(scenes_t *scene, char **grid)
{
    static int first_time = TRUE;

    if ((grid[(int)scene->pos.y][(int)scene->pos.x] == 'H'
                        && sfKeyboard_isKeyPressed(sfKeyF) == sfTrue))
        scene->player->hp = 100;
    if ((grid[(int)scene->pos.y][(int)scene->pos.x] == 'C'
                        && sfKeyboard_isKeyPressed(sfKeyF) == sfTrue)) {
        scene->player->hud->active[1] = TRUE;
        if (first_time == TRUE) {
            scene->player->normal_attack += 10;
            scene->player->special_attack += 10;
            first_time = FALSE;
        }
    }
    if ((grid[(int)scene->pos.y][(int)scene->pos.x] == 'c'
                        && sfKeyboard_isKeyPressed(sfKeyF) == sfTrue))
        scene->player->hud->active[2] = TRUE;
    check_open_door(scene, grid);
}