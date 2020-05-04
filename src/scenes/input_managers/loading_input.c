/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_input
*/

#include "prototype.h"
#include "my_rpg.h"
#include "libmy.h"

void loading_input(__attribute__((unused)) scenes_t *scene,
                                        window_t *window_data)
{
    if (window_data->event.type == sfEvtKeyReleased) {
        window_data->current_scene = CHARACTER_SCENE;
        return;
    }
}