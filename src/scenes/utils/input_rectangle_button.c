/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** character_input
*/

#include "prototype.h"
#include "my_rpg.h"

sfFloatRect get_hitbox(buttons_t *button, sfVector2u size)
{
    sfFloatRect hitbox;

    hitbox.top = button->hitbox.top * size.y;
    hitbox.left = button->hitbox.left * size.x;
    hitbox.height = button->hitbox.height * size.y;
    hitbox.width = button->hitbox.width * size.x;
    return (hitbox);
}

void input_rectangle_button(sfRenderWindow *window, sfEvent event,
                                                        buttons_t *button)
{
    sfVector2i pos;
    sfFloatRect hitbox;
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2i window_pos = sfRenderWindow_getPosition(window);

    button->selected = FALSE;
    if (button->current_color == 2 && event.type == sfEvtMouseButtonReleased)
        button->current_text = (button->text
            [button->current_text + 1] != NULL) ? button->current_text + 1 : 0;
    button->current_color = 0;
    hitbox = get_hitbox(button, size);
    pos.x = ((mouse_pos.x - window_pos.x) - hitbox.left);
    pos.y = ((mouse_pos.y - window_pos.y) - hitbox.top) - 30;
    if (pos.x >= 0 && pos.x <= hitbox.width
                                    && pos.y >= 0 && pos.y <= hitbox.height)
        button->current_color = 1;
    if (button->current_color == 1 && event.type == sfEvtMouseButtonPressed) {
        button->current_color = 2;
        button->selected = TRUE;
    }
}