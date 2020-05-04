/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** movement_input
*/

#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

void idle_horizontal(scenes_t *scene, char **grid, short *i, sfVector2f *dir)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue && grid
    [(int)scene->pos.y][(int)scene->pos.x - 1] != '1') {
        dir->y = 0;
        dir->x = -0.1;
        *i += 1;
        scene->pos.x -= 1;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue && grid
    [(int)scene->pos.y][(int)scene->pos.x + 1] != '1') {
        dir->y = 0;
        dir->x = 0.1;
        *i += 1;
        scene->pos.x += 1;
    }
}

void idle(scenes_t *scene, char **grid, short *i, sfVector2f *dir)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue && grid
    [(int)scene->pos.y - 1][(int)scene->pos.x] != '1') {
        dir->y = -0.1;
        dir->x = 0;
        *i += 1;
        scene->pos.y -= 1;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue
    && grid[(int)scene->pos.y + 1]
    [(int)scene->pos.x] != '1') {
        dir->y = 0.1;
        dir->x = 0;
        *i += 1;
        scene->pos.y += 1;
    }
    else
        idle_horizontal(scene, grid , i, dir);
}

void move_keys(scenes_t *scene, char **grid, short *i)
{
    static sfVector2f dir = {0, 0};

    if (*i == 0)
        idle(scene, grid, i, &dir);
    else if (*i <= 10) {
        sfView_move(scene->view, (sfVector2f)
        {.x = 24 * dir.x, .y = 24 * dir.y});
        move_every_sprite(scene->player->animated_sprite->sprites, (sfVector2f)
        {.x = 24 * dir.x, .y = 24 * dir.y});
        *i += 1;
    }
    else
        *i = 0;
}
