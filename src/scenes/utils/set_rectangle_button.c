/*
** EPITECH PROJECT, 2020
** set_button.c
** File description:
** set button
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "prototype.h"
#include "struct.h"

buttons_t *set_default_button_value
(buttons_t *button, sfColor *color, sfFloatRect rect)
{
    button->selected = FALSE;
    button->current_text = 0;
    button->current_color = 0;
    button->index = 0;
    button->color = color;
    button->hitbox = rect;
    button->button_type = RECTANGLE;
    return (button);
}

buttons_t *set_button
(char **tab, window_t *window_data, sfColor *color, sfFloatRect rect)
{
    int index = 0;
    buttons_t *button = malloc(sizeof(buttons_t));

    if (button == NULL)
        return (NULL);
    button = set_default_button_value(button, color, rect);
    rect = get_window_rect(window_data->render_window, rect);
    button->rect = create_button_rectangleshape(color[0], rect);
    rect.top -= (rect.height / 7);
    button->text = malloc(sizeof(sfText *) * (get_tab_len(tab) + 1));
    for (;tab[index] != NULL; index++)
        button->text[index] = create_button_text
        (tab[index], window_data->fonts[0], color[3], rect);
    button->text[index] = NULL;
    return (button);
}