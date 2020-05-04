/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_scene_constructor
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "prototype.h"
#include "libmy.h"

buttons_t **create_input_button(window_t *window_data, buttons_t **button)
{
    int index = 0;
    sfFloatRect rect = {0.5, 0.8, 0.18, 0.05};
    sfColor color = sfColor_fromRGBA(220, 220, 220, 255);

    if (button == NULL)
        return (NULL);
    while (button[index] != NULL)
        index++;
    if (button == NULL)
        return (NULL);
    button[index] = set_input(my_strdup("NAME     \0"),
    window_data, color, rect);
    index++;
    button[index] = NULL;
    return (button);
}

static buttons_t **create_rectangle_button
(window_t *window_data, buttons_t **button)
{
    sfFloatRect rect = {0.1, 0.8, 0.18, 0.05};
    sfColor *color = malloc(sizeof(sfColor) * 4);

    if (button == NULL || color == NULL)
        return (NULL);
    color[0] = sfColor_fromRGBA(86, 152, 204, 255);
    color[1] = sfColor_fromRGBA(114, 214, 206, 255);
    color[2] = sfColor_fromRGBA(238, 142, 46, 255);
    color[3] = sfColor_fromRGBA(255, 255, 255, 255);
    button[0] = set_button(my_str_to_word_array
    ("ELF\nWIZZARD\nKNIGHT\0", "\n"), window_data, color, rect);
    rect.left +=  0.2;
    button[1] = set_button(my_str_to_word_array
    ("MEN\nWOMEN\0", "\n"), window_data, color, rect);
    rect.left +=  0.2 + 0.2;
    button[2] = set_button(my_str_to_word_array
    ("START\n\0", "\n"), window_data, color, rect);
    button[3] = NULL;
    return (button);
}

scenes_t *character_constructor(scenes_t *scene, window_t *window_data)
{
    scene->game_objects = NULL;
    scene->background = get_background_asset
    ("character_selec_background.jpg", window_data->loaded_assets->background);
    scene->music = window_data->musics[CELESTIAL];
    scene->music_start = FALSE;
    scene->buttons = malloc(sizeof(buttons_t *) * 5);
    scene->buttons = create_rectangle_button(window_data, scene->buttons);
    scene->buttons = create_input_button(window_data, scene->buttons);
    return (scene);
}
