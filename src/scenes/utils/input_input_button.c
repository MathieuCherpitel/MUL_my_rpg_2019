/*
** EPITECH PROJECT, 2020
** input.c
** File description:
** input
*/

#include <stddef.h>
#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

void input_delete(sfEvent event, buttons_t *input)
{
    if (event.key.code == 59 &&
        input->index >= 0 && input->selected == TRUE) {
        if (input->index > 0)
            input->index--;
        input->str[input->index] = ' ';
    }
}

void input_number(sfEvent event, buttons_t *input)
{
    int index = input->index;

    if ((event.key.code >= 75 && event.key.code <= 94) &&
        (input->str[index + 1] != '\0' && input->selected == TRUE)) {
        input->str[index] = event.key.code - (75 - '0');
        input->index++;
    }
}

void input_alphabetical(sfEvent event, buttons_t *input)
{
    int index = input->index;

    if ((event.key.code >= 0 && event.key.code <= 25) &&
        (input->str[index + 1] != '\0' && input->selected == TRUE)) {
        input->str[index] = event.key.code + 'A';
        input->index++;
    }
}

void input_enter(sfEvent event, buttons_t *input, buttons_t *next_input)
{
    if (event.key.code == 58 && input->selected == TRUE) {
        input->selected = FALSE;
        event.key.code = -1;
        if (next_input != NULL)
            next_input->selected = TRUE;
    }
}
