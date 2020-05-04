/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_text
*/

#include <stdlib.h>
#include "prototype.h"
#include "my_rpg.h"
#include "libmy.h"

void create_enemy_text(sfText **text, enemy_t *enemy, sfFont *font)
{
    text[6] = create_text(font, enemy->name,
                                            (sfColor){100, 100, 100, 255},42);
    text[6] = move_text(text[6], 1600, 10);
    text[7] = create_text(font, "Hp: ", (sfColor){0, 255, 0, 255},42);
    text[7] = move_text(text[7], 1510, 200);
    text[8] = create_text(font, my_itoa(enemy->hp),
                                                (sfColor){0, 255, 0, 255},42);
    text[8] = move_text(text[8], 1600, 200);
}

void create_player_text(sfText **text, sfFont *font)
{
    text[0] = create_text(font, "vs", (sfColor){150, 150, 150, 255},42);
    text[0] = move_text(text[0], 910, 1);
}

sfText **create_scene_text(window_t *window_data)
{
    int text_count = 1;
    sfFont *poppin = window_data->fonts[POPPINS];
    sfText **text = malloc(sizeof(sfText *) * (text_count + 1));

    if (text == NULL)
        return (NULL);
    create_player_text(text, poppin);
    text[text_count] = NULL;
    return (text);
}

void create_fight_special_text(sfText **text, window_t *window_data)
{
    sfFont *poppin = window_data->fonts[POPPINS];

    text[0] = create_text(poppin, "", (sfColor){100, 100, 100, 255}, 42);
    text[0] = move_text(text[0], 850, 200);
    text[1] = create_text(poppin, "", (sfColor){255, 0, 0, 255}, 42);
    text[1] = move_text(text[1], 300, 200);
    text[2] = create_text(poppin, "", (sfColor){255, 0, 0, 255}, 42);
    text[2] = move_text(text[2], 1400, 200);
    text[3] = NULL;
}

sfText **create_special_text(window_t *window_data)
{
    int text_count = 4;
    sfText **text = malloc(sizeof(sfText *) * (text_count + 1));

    if (text == NULL)
        return (NULL);
    create_fight_special_text(text, window_data);
    return (text);
}