/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** character_input
*/

#include "prototype.h"
#include "my_rpg.h"

void input_event(sfEvent event, buttons_t **input)
{
    if (input == NULL || event.type != sfEvtKeyPressed)
        return;
    for (int i = 0; input[i] != NULL; i++) {
        if (input[i]->button_type == INPUT) {
            input_alphabetical(event, input[i]);
            input_number(event, input[i]);
            input_delete(event, input[i]);
            sfText_setString(input[i]->text[0], input[i]->str);
        }
    }
}

void button_event(scenes_t *scene, window_t *window)
{
    sfColor color;

    if (scene->buttons == NULL)
        return;
    for (int i = 0; scene->buttons[i] != NULL; i++) {
        if (scene->buttons[i]->button_type == RECTANGLE) {
            input_rectangle_button
            (window->render_window, window->event, scene->buttons[i]);
            color = scene->buttons[i]->color[scene->buttons[i]->current_color];
            sfRectangleShape_setFillColor(scene->buttons[i]->rect, color);
        }
    }
}

void character_input(scenes_t *scene, window_t *window_data)
{
    sfVector2f scale = {.x = 0.14285714285, .y = 0.14285714285};

    button_event(scene, window_data);
    if (scene->buttons[2]->selected == TRUE) {
        scale_animated_player(scene->player->animated_sprite, FALSE, scale);
        scale_player(window_data->loaded_assets->player, FALSE, scale);
        create_hud(window_data, scene->player, scene->buttons[0]->current_text,
        (scene->buttons[1]->current_text * 3));
        sfMusic_pause(scene->music);
        window_data->current_scene = WORLD;
    }
    input_event(window_data->event, scene->buttons);
}