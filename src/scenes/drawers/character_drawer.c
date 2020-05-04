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

void display_sprite_run
(animated_sprites_t *animated_sprite, window_t *window_data)
{
    static int run[3] = {0, FALSE, FALSE};

    animated_sprite->sprite_count = run[0];
    animated_sprite->even = run[1];
    animated_sprite->odd = run[2];
    change_sprite_count(window_data, animated_sprite, RUN);
    run[0] = animated_sprite->sprite_count;
    run[1] = animated_sprite->even;
    run[2] = animated_sprite->odd;
    sfSprite_setPosition(animated_sprite->sprites[run[0]],
    (sfVector2f){.x = 200, .y = 200});
    sfRenderWindow_drawSprite(window_data->render_window,
    animated_sprite->sprites[run[0]], NULL);
}

void display_sprite_idle_hit(animated_sprites_t *animated_sprite,
                                                window_t *window_data)
{
    static int idle[3] = {4, FALSE, FALSE};

    animated_sprite->sprite_count = idle[0];
    animated_sprite->even = idle[1];
    animated_sprite->odd = idle[2];
    change_sprite_count(window_data, animated_sprite, IDLE);
    idle[0] = animated_sprite->sprite_count;
    idle[1] = animated_sprite->even;
    idle[2] = animated_sprite->odd;
    sfSprite_setPosition(animated_sprite->sprites[idle[0]],
    (sfVector2f){.x = 800, .y = 200});
    sfRenderWindow_drawSprite(window_data->render_window,
    animated_sprite->sprites[idle[0]], NULL);
    sfSprite_setPosition(animated_sprite->sprites[8],
    (sfVector2f){.x = 1400, .y = 200});
    sfRenderWindow_drawSprite(window_data->render_window,
    animated_sprite->sprites[8], NULL);
}

void display_button(scenes_t * scene, window_t *window_data)
{
    for (int i = 0; scene->buttons[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window_data->render_window,
        scene->buttons[i]->rect, NULL);
        sfRenderWindow_drawText(window_data->render_window,
        scene->buttons[i]->text[scene->buttons[i]->current_text], NULL);
    }
}

void character_drawer(scenes_t *scene, window_t *window_data)
{
    static int check = FALSE;
    sfVector2f scale = {.x = 7, .y = 7};
    char *type[4] = {"elf_\0", "wizzard_\0", "knight_\0", NULL};
    char *gender[3] = {"m.png\0", "w.png\0", NULL};
    char *name = str_fusion(type[scene->buttons[0]->current_text],
    
    gender[scene->buttons[1]->current_text]);
    display_background(scene, window_data);
    scene->music_start = play_music(scene, scene->music_start);
    check = scale_player(window_data->loaded_assets->player, check, scale);
    display_button(scene, window_data);
    scene->player->animated_sprite->sprites = get_sprite_asset
                                (name, window_data->loaded_assets->player);
    display_sprite_idle_hit(scene->player->animated_sprite, window_data);
    display_sprite_run(scene->player->animated_sprite, window_data);
    scene->player->name = scene->buttons[3]->str;
}
