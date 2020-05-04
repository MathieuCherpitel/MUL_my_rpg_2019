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

buttons_t *set_default_input_value
(buttons_t *input, char *str, sfFloatRect rect)
{
    int index = 0;

    while (str[index] != ' ' && str[index] != '\0')
        index++;
    input->str = str;
    input->selected = TRUE;
    input->current_text = 0;
    input->index = index;
    input->hitbox = rect;
    input->button_type = INPUT;
    return (input);    
}

buttons_t *set_input
(char *str, window_t *window_data, sfColor color, sfFloatRect rect)
{
    buttons_t *input = malloc(sizeof(buttons_t));

    if (input == NULL)
        return (NULL);
    input = set_default_input_value(input, str, rect);
    rect = get_window_rect(window_data->render_window, rect);
    input->rect = create_button_rectangleshape(color, rect);
    rect.top -= (rect.height / 7);
    input->text = malloc(sizeof(sfText * ) * 2);
    input->text[0] =
    create_button_text(str, window_data->fonts[0], sfBlack, rect);
    input->text[1] = NULL;
    return (input);
}

