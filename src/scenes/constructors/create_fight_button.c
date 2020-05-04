/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_fight_button
*/

#include <stdlib.h>
#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

buttons_t **allocate_buttons(int button_count)
{
    int count = 0;
    buttons_t **buttons = malloc(sizeof(buttons_t *) * (button_count + 1));

    if (buttons == NULL)
        return (NULL);
    while (count < button_count) {
        buttons[count] = malloc(sizeof(buttons_t));
        if (buttons[count] == NULL)
            return (NULL);
        count++;
    }
    buttons[count] = NULL;
    return (buttons);
}

buttons_t *create_fight_button
(buttons_t *button, window_t *window_data, char *string, sfVector2f pos)
{
    button->button_type = SPRITE;
    button->sprite_to_draw = sfSprite_copy(
        get_any_asset("fight_button.png", window_data->loaded_assets->UI));
    sfSprite_scale(button->sprite_to_draw, (sfVector2f){.x = 2, .y = 2});
    sfSprite_setPosition(button->sprite_to_draw, pos);
    button->text = malloc(sizeof(sfText *) * 1);
    button->text[0] = create_text(window_data->fonts[POPPINS],
    string, (sfColor){255, 255, 255, 255}, 40);
    if (my_strcmp(string, "heal") == 0)
        button->text[0] = move_text(button->text[0],
        (int)pos.x + 37, (int)pos.y + 5);
    else
        button->text[0] = move_text(button->text[0],
        (int)pos.x + 9, (int)pos.y + 5);
    button->selected = FALSE;
    return (button);
}

buttons_t **create_fight_scene_buttons(scenes_t *scene, window_t *window_data)
{
    int button_count = 3;

    scene->buttons = allocate_buttons(button_count);
    if (scene->buttons == NULL)
        return (NULL);
    scene->buttons[0] = create_fight_button(scene->buttons[0],
    window_data, "normal", (sfVector2f){.x = 115, .y = 350});
    scene->buttons[1] = create_fight_button(scene->buttons[1],
    window_data, "special", (sfVector2f){.x = 310, .y = 350});
    scene->buttons[2] = create_fight_button(scene->buttons[2],
    window_data, "heal", (sfVector2f){.x = 520, .y = 350});
    scene->buttons[0]->callback = normal_attack;
    scene->buttons[1]->callback = special_attack;
    scene->buttons[2]->callback = heal;
    scene->buttons[3] = NULL;
    return (scene->buttons);
}