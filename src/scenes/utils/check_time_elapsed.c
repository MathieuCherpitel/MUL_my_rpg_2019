/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_drawer
*/

#include "my_rpg.h"
#include "prototype.h"

int check_elapsed_time(sfClock *clock, float check, float time_to_wait)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asMilliseconds(time);

    if (check == 0)
        check = seconds;
    if ((check + time_to_wait) >= seconds)
        return (SUCCESS);
    return (check);
}