/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** world_scene_constructor
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "libmy.h"
#include "prototype.h"

sfSprite **sprites_copy(sfSprite **sprite)
{
    int len = 0;
    int index = 0;
    sfSprite **spritecpy;

    while (sprite[len++] != NULL);
    spritecpy = malloc(sizeof(sfSprite *) * (len + 1));
    while (sprite[index] != NULL) {
        spritecpy[index] = sfSprite_copy(sprite[index]);
        index++;
    }
    spritecpy[index] = NULL;
    return (spritecpy);
}

void set_npc_sprite_position(npc_t *npc, int index)
{
    sfVector2f pos1 = {.x = 15, .y = 4};
    sfVector2f pos2 = {.x = 45, .y = 47};
    sfVector2f pos3 = {.x = 62, .y = 43};
    sfVector2f pos[] = {pos1, pos2, pos3};

    npc->dialog = sprites_copy(npc->dialog);
    npc->animated_sprite->sprites = sprites_copy
                                    (npc->animated_sprite->sprites);
    set_sprite(npc->dialog, pos[index]);
    pos[index].x += 4;
    pos[index].y += 2;
    set_sprite(npc->animated_sprite->sprites, pos[index]);
}

npc_t **set_npc(window_t *window_data)
{
    char *name[] = {"Didier", "Alice", "Fabrice", NULL};
    char *asset_dialog[] = {"bubble1.png", "bubble2.png",
                                                "bubble3.png", NULL};
    char *asset_npc[] = {"npc_m.png", "npc_w.png", "npc_m.png", NULL};
    npc_t **npc = malloc(sizeof(npc_t *) * (get_tab_len(name) + 1));

    for (int i = 0; name[i] != NULL; i++) {
        npc[i] = malloc(sizeof(npc_t));
        npc[i]->name = name[i];
        npc[i]->animated_sprite = malloc(sizeof(animated_sprites_t));
        npc[i]->animated_sprite->even = FALSE;
        npc[i]->animated_sprite->odd = FALSE;
        npc[i]->animated_sprite->sprite_count = 0;
        npc[i]->animated_sprite->sprites = get_sprite_asset(asset_npc[i],
                                            window_data->loaded_assets->npc);
        npc[i]->current_dialog = 0;
        npc[i]->active = FALSE;
        npc[i]->dialog = get_sprite_asset(asset_dialog[i],
                                            window_data->loaded_assets->UI);
        set_npc_sprite_position(npc[i], i);
    }
    npc[get_tab_len(name)] = NULL;
    return (npc);
}

void set_world_data(scenes_t *scene, window_t *window_data)
{
    scene->view = sfView_create();
    scene->game_objects = malloc(sizeof(game_objects_t));
    scene->game_objects->npc = set_npc(window_data);
    scene->game_objects->enemies = NULL;
    scene->buttons = NULL;
    scene->background = get_background_asset("world_1.png",
    window_data->loaded_assets->background);
    scene->music = window_data->musics[NOCTURIAL];
    scene->music_start = FALSE;
    scene->text = NULL;
    scene->pointers = malloc(8 * 4);
}

scenes_t *world_constructor(scenes_t *scene, window_t *window_data)
{
    sfVector2f pos = PLAYER_HOUSE;
    char *file_buf = my_read_file("rpg_assets/backgrounds/world_1.evt");

    if (!file_buf)
        return NULL;
    set_world_data(scene, window_data);
    if (!scene->pointers)
        return NULL;
    scene->pos = pos;
    scene->GRID = my_str_to_word_array(file_buf, "\n");
    if (!scene->GRID)
        return NULL;
    scene->WORLD_PTR_MAX = NULL;
    sfView_setSize(scene->view, (sfVector2f){.x = 1920, .y = 1080});
    sfView_setCenter(scene->view, (sfVector2f){.x = (24 * 24) + 12,
                                                    .y = (15 * 24) + 12});
    sfView_zoom(scene->view, 0.5);
    free(file_buf);
    return (scene);
}