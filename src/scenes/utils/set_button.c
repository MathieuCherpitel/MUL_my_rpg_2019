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

sfText *create_button_text(char *str, sfFont *font, sfColor color,
                                                        sfFloatRect rect)
{
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setFillColor(text, color);
    sfText_setCharacterSize(text, rect.height);
    sfText_setPosition(text, (sfVector2f){rect.left, rect.top});
    return (text);
}

sfRectangleShape *create_button_rectangleshape(sfColor color, sfFloatRect rect)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left, rect.top});
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width, rect.height});
    sfRectangleShape_setFillColor(shape, color);
    return (shape);
}

sfFloatRect get_window_rect(sfRenderWindow *window, sfFloatRect rect)
{
    sfVector2u screen_size = sfRenderWindow_getSize(window);
    
    rect.top *= screen_size.y;
    rect.left *= screen_size.x;
    rect.height *= screen_size.y;
    rect.width *= screen_size.x;
    return (rect);
}