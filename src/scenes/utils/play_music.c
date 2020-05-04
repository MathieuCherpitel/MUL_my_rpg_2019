/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_music
*/

#include "my_rpg.h"
#include "prototype.h"

int play_music(scenes_t*scene, int check)
{
    if (check != FALSE)
        return (TRUE);
    sfMusic_play(scene->music);
    return (TRUE);
}