/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** dungeon_game_obj
*/

#include <stdlib.h>
#include "prototype.h"
#include "my_rpg.h"

void set_npc_dungeon_sprite_position(npc_t *npc, int index)
{
    sfVector2f pos1 = {.x = 42, .y = 66};
    sfVector2f pos[] = {pos1};

    npc->dialog = sprites_copy(npc->dialog);
    npc->animated_sprite->sprites =
    sprites_copy(npc->animated_sprite->sprites);
    set_sprite(npc->dialog, pos[index]);
    pos[index].x += 4;
    pos[index].y += 2;
    set_sprite(npc->animated_sprite->sprites, pos[index]);
}

npc_t **set_dungeon_npc(window_t *window_data)
{
    char *name[] = {"Fabrice", NULL};
    char *asset_dialog[] = {"bubble3.png", NULL};
    char *asset_npc[] = {"npc_m.png", NULL};
    npc_t **npc = malloc(sizeof(npc_t *) * (get_tab_len(name) + 1));

    for (int i = 0; name[i] != NULL; i++) {
        npc[i] = malloc(sizeof(npc_t));
        npc[i]->name = name[i];
        npc[i]->animated_sprite = malloc(sizeof(animated_sprites_t));
        npc[i]->animated_sprite->even = FALSE;
        npc[i]->animated_sprite->odd = FALSE;
        npc[i]->animated_sprite->sprite_count = 0;
        npc[i]->animated_sprite->sprites =
        get_sprite_asset(asset_npc[i], window_data->loaded_assets->npc);
        npc[i]->current_dialog = 0;
        npc[i]->active = FALSE;
        npc[i]->dialog =
        get_sprite_asset(asset_dialog[i], window_data->loaded_assets->UI);
        set_npc_dungeon_sprite_position(npc[i], i);
    }
    npc[get_tab_len(name)] = NULL;
    return (npc);
}

game_objects_t *dungeon_game_object(scenes_t *scene, window_t *window_data)
{
    scene->game_objects = malloc(sizeof(game_objects_t));
    scene->game_objects->enemies = allocate_dungeon_enemies(scene);
    scene->game_objects->npc = set_dungeon_npc(window_data);
    scene->game_objects->enemies[0] = create_enemy(scene->game_objects->enemies[0], window_data, "goblin", EASY);
    set_sprite(scene->game_objects->enemies[0]->animated_sprite->sprites, (sfVector2f){.x = 30.85, .y = 68});
    scene->game_objects->enemies[1] = create_enemy(scene->game_objects->enemies[1], window_data, "imp", EASY);
    set_sprite(scene->game_objects->enemies[1]->animated_sprite->sprites, (sfVector2f){.x = 30.85, .y = 52});
    scene->game_objects->enemies[2] = create_enemy(scene->game_objects->enemies[2], window_data, "skelet", EASY);
    set_sprite(scene->game_objects->enemies[2]->animated_sprite->sprites, (sfVector2f){.x = 20, .y = 52});
    scene->game_objects->enemies[3] = create_enemy(scene->game_objects->enemies[3], window_data, "necromancer", MEDIUM);
    set_sprite(scene->game_objects->enemies[3]->animated_sprite->sprites, (sfVector2f){.x = 10, .y = 55});
    scene->game_objects->enemies[4] = create_enemy(scene->game_objects->enemies[4], window_data, "swamp", EASY);
    set_sprite(scene->game_objects->enemies[4]->animated_sprite->sprites, (sfVector2f){.x = 44, .y = 52});
    scene->game_objects->enemies[5] = create_enemy(scene->game_objects->enemies[5], window_data, "orc_shaman", MEDIUM);
    set_sprite(scene->game_objects->enemies[5]->animated_sprite->sprites, (sfVector2f){.x = 55, .y = 51});
    scene->game_objects->enemies[6] = create_enemy(scene->game_objects->enemies[6], window_data, "big_zombie", BOSS);
    set_sprite(scene->game_objects->enemies[6]->animated_sprite->sprites, (sfVector2f){.x = 60, .y = 60});
    scene->game_objects->enemies[7] = create_enemy(scene->game_objects->enemies[7], window_data, "orc_warrior", MEDIUM);
    set_sprite(scene->game_objects->enemies[7]->animated_sprite->sprites, (sfVector2f){.x = 11, .y = 29});
    scene->game_objects->enemies[8] = create_enemy(scene->game_objects->enemies[8], window_data, "muddy", EASY);
    set_sprite(scene->game_objects->enemies[8]->animated_sprite->sprites, (sfVector2f){.x = 50, .y = 20});
    scene->game_objects->enemies[9] = create_enemy(scene->game_objects->enemies[9], window_data, "ice_zombie", MEDIUM);
    set_sprite(scene->game_objects->enemies[9]->animated_sprite->sprites, (sfVector2f){.x = 20, .y = 20});
    scene->game_objects->enemies[10] = create_enemy(scene->game_objects->enemies[10], window_data, "zombie", EASY);
    set_sprite(scene->game_objects->enemies[10]->animated_sprite->sprites, (sfVector2f){.x = 40, .y = 28});
    scene->game_objects->enemies[11] = create_enemy(scene->game_objects->enemies[11], window_data, "big_demon", BOSS);
    set_sprite(scene->game_objects->enemies[11]->animated_sprite->sprites, (sfVector2f){.x = 30, .y = 6});
    return (scene->game_objects);
}