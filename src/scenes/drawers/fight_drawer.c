/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_drawer
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "prototype.h"

sfSprite **copy_player_sprite(scenes_t *scene)
{
    int count = 0;
    sfSprite **copy = malloc(sizeof(sfSprite *) * (10));

    if (copy == NULL)
        return (NULL);
    while (scene->player->animated_sprite->sprites[count] != NULL) {
        copy[count] = sfSprite_copy
                    (scene->player->animated_sprite->sprites[count]);
        count++;
    }
    copy[count] = NULL;
    return (copy);
}

void place_player(scenes_t *scene, window_t *window_data)
{
    static int first_time = TRUE;
    sfSprite **copy;
    static animated_sprites_t *animated_sprites;

    if (first_time == TRUE) {
        copy = copy_player_sprite(scene);
        if (copy == NULL)
            return;
        place_scale_sprite_sheet(copy, (sfVector2f){.x = 400, .y = 600},
                                        (sfVector2f){.x = 7, .y = 7}); 
        animated_sprites = malloc(sizeof(animated_sprites_t));
        animated_sprites->even = FALSE;
        animated_sprites->odd = FALSE;
        animated_sprites->sprite_count = 0;
        animated_sprites->sprites = copy;
        first_time = FALSE;
    }
    display_animated_sprite(window_data, animated_sprites, IDLE);
}

void fight_drawer(scenes_t *scene, window_t *window_data)
{

    scene->music_start = play_music(scene, scene->music_start);
    sfRenderWindow_setView(window_data->render_window,
                    sfRenderWindow_getDefaultView(window_data->render_window));
    if (scene->player->mana < 40) {
        sfText_setColor(scene->buttons[1]->text[0], (sfColor){255, 0, 0, 255});
        sfText_setColor(scene->buttons[2]->text[0], (sfColor){255, 0, 0, 255});
    }
    if (scene->player->hp >= 100)
        scene->player->hp = 100;
    display_background(scene, window_data);
    place_player(scene, window_data);
    display_animated_sprite(window_data,
                                scene->current_enemy->animated_sprite, RUN);
    display_text(scene, window_data);
    display_special_text(scene, window_data);
    display_fight_buttons(scene->buttons, window_data);
    display_hud(scene->player, window_data);
    display_hud_enemy(window_data,scene->current_enemy->hp,
                scene->current_enemy->name, (sfVector2f){.x = 1920, .y = 0});
    sfRenderWindow_display(window_data->render_window);
}