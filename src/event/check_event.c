/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_event
*/

#include "my_rpg.h"
#include "prototype.h"

void check_event(window_t *window_data, scenes_t *scenes, int scene_index)
{
    while (sfRenderWindow_pollEvent(window_data->render_window, &window_data->event)) {
        if (window_data->event.type == sfEvtClosed) {
            sfRenderWindow_close(window_data->render_window);
        }
        if (scene_index == CHARACTER_SCENE)
            scenes->input_method(scenes, window_data);
    }
    if (scene_index != CHARACTER_SCENE)
        scenes->input_method(scenes, window_data);
}