/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** world_drawer
*/

#include "prototype.h"
#include "my_rpg.h"

void display_entities(scenes_t *scene, window_t *window_data)
{
    int count = 0;
    sfVector2f pos;

    while (scene->game_objects->enemies[count] != NULL) {
        pos = sfSprite_getPosition(scene->game_objects->enemies[count]->animated_sprite->sprites[0]);
        if (scene->game_objects->enemies[count]->status == ALIVE)
            display_animated_sprite(window_data, scene->game_objects->enemies[count]->animated_sprite, RUN);
        count++;
    }
}

sfView *do_once(scenes_t *scene, sfView *min, sfView *stats)
{
    min = sfView_copy(scene->view);
    stats = sfView_create();
    sfView_zoom(min, 4.4);
    sfView_setViewport(stats, (sfFloatRect){0, 0, 0, 1});
    sfView_setViewport(min, (sfFloatRect){0.75, 0, 0.25, 0.25});
    place_scale_sprite_sheet(scene->player->animated_sprite->sprites,
    (sfVector2f){.x = 24.2 * 24, .y = 14.58 * 24}, (sfVector2f){5, 5});
    return min;
}

void world_drawer(scenes_t *scene, window_t *window_data)
{
    static int i = 0;
    static sfView *min;
    static sfView *stats;

    scene->music_start = play_music(scene, scene->music_start);
    if (i == 0) {
        min = do_once(scene, min, stats);
        i++;
    }
    sfRenderWindow_clear(window_data->render_window, sfBlack);
    sfRenderWindow_setView(window_data->render_window, scene->view);
    display_background(scene, window_data);
    display_animated_sprite(window_data, scene->player->animated_sprite, RUN);
    if (scene->game_objects != NULL && scene->game_objects->enemies != NULL)
        display_entities(scene, window_data);


    int index;
    if (scene->game_objects != NULL && scene->game_objects->npc != NULL) {
        for (int i = 0; scene->game_objects->npc[i] != NULL; i++) {
            display_animated_sprite(window_data, scene->game_objects->npc[i]->animated_sprite, IDLE);
            if (scene->game_objects->npc[i]->active == TRUE) {
                index = scene->game_objects->npc[i]->current_dialog;
                sfRenderWindow_drawSprite(window_data->render_window, scene->game_objects->npc[i]->dialog[index], NULL);
            }
        }
    }

    sfRenderWindow_setView(window_data->render_window, min);
    display_background(scene, window_data);
    sfRenderWindow_drawSprite(window_data->render_window, scene->player->animated_sprite->sprites[0], NULL);
    sfRenderWindow_setView(window_data->render_window, sfRenderWindow_getDefaultView(window_data->render_window));
    display_hud(scene->player, window_data);
    // sfRenderWindow_setView(window_data->render_window, stats);
}