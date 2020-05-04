/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_drawer
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "prototype.h"
#include "my_rpg.h"
#include "libmy.h"

int time_animation(sfClock *clock, animated_sprites_t *animated_sprites)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float secondes = sfTime_asMilliseconds(time) / 60;

    if ((int)secondes % 2 == 0)
        animated_sprites->even = TRUE;
    else
        animated_sprites->odd = TRUE;
    if (animated_sprites->even == TRUE && animated_sprites->odd == TRUE) {
        animated_sprites->even = FALSE;
        animated_sprites->odd = FALSE;
        return (1);
    }
    return (0);
}

void change_sprite_count(window_t *window_data,
                    animated_sprites_t *animated_sprites, int animation)
{
    switch (animation) {
    case (RUN):
        animated_sprites->sprite_count += time_animation
                                (window_data->clock, animated_sprites);
        if (animated_sprites->sprite_count >= 4)
            animated_sprites->sprite_count = 0;
        break;
    case (IDLE):
        if (animated_sprites->sprite_count < 4)
            animated_sprites->sprite_count = 4;
        animated_sprites->sprite_count += time_animation
                                (window_data->clock, animated_sprites);
        if (animated_sprites->sprite_count >= 8)
            animated_sprites->sprite_count = 4;
        break;
    case (HIT):
        animated_sprites->sprite_count = 8;
        break;
    }
}

void display_animated_sprite(window_t *window_data,
                    animated_sprites_t *animated_sprites, int animation)
{
    change_sprite_count(window_data, animated_sprites, animation);
    if (animated_sprites->sprites == NULL)
        return;
    sfRenderWindow_drawSprite(window_data->render_window,
        animated_sprites->sprites[animated_sprites->sprite_count], NULL);
}