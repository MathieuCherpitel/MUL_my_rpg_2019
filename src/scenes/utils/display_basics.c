/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_background
*/

#include "prototype.h"
#include "my_rpg.h"

void display_buttons(buttons_t **buttons, window_t *window_data)
{
    int count = 0;
    sfRenderWindow *w = window_data->render_window;

    if (buttons == NULL)
        return;
    while (buttons[count] != NULL) {
        if (buttons[count]->button_type == RECTANGLE)
            sfRenderWindow_drawRectangleShape(w, buttons[count]->rect, NULL);
        count++;
    }
}

void display_fight_buttons(buttons_t **buttons, window_t *window_data)
{
    int count = 0;

    while (buttons[count] != NULL) {
        sfRenderWindow_drawSprite(window_data->render_window, 
                                        buttons[count]->sprite_to_draw, NULL);
        sfRenderWindow_drawText(window_data->render_window,
                                                buttons[count]->text[0], NULL);
        count++;
    }
}

void display_background(scenes_t *scene, window_t *window_data)
{
    sfRenderWindow_drawSprite(window_data->render_window,
                                                    scene->background, NULL);
}

void display_special_text(scenes_t *scene, window_t *window_data)
{
    int count = 0;

    while (scene->special_text[count] != NULL) {
        sfRenderWindow_drawText(window_data->render_window,
                                            scene->special_text[count], NULL);
        count++;
    }
}

void display_text(scenes_t *scene, window_t *window_data)
{
    int count = 0;

    while (scene->text[count] != NULL) {
        sfRenderWindow_drawText(window_data->render_window,
                                                    scene->text[count], NULL);
        count++;
    }
}