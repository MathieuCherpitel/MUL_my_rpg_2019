/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** world_input
*/

#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

void move_every_sprite(sfSprite **sprites, sfVector2f pos)
{
    for (int i = 0; sprites[i]; i++)
        sfSprite_move(sprites[i], pos);
}

void move(scenes_t *scene, sfView *view, float y_offset, float x_offset)
{
    move_every_sprite(scene->player->animated_sprite->sprites, MOVE_VEC);
    sfView_move(view, MOVE_VEC);
    scene->pos.x += x_offset;
    scene->pos.y += y_offset;
}

void event_keys(scenes_t *scene, window_t *window_data, char **grid)
{
    if (window_data->event.type == sfEvtKeyReleased && window_data->event.key.code == sfKeyF &&
     grid[(int)scene->pos.y][(int)scene->pos.x] != '0'
        && grid[(int)scene->pos.y][(int)scene->pos.x] != '1') {
        if (grid[(int)scene->pos.y][(int)scene->pos.x] == '2') {
            move(scene, scene->view, 1, 0);
            place_scale_sprite_sheet(scene->player->
            animated_sprite->sprites,
            (sfVector2f){.x = 169, .y = 230}, (sfVector2f){1, 1});
            window_data->current_scene = HOUSE;
        }
        if (grid[(int)scene->pos.y][(int)scene->pos.x] == '3') {
            move(scene, scene->view, -1, 0);
            place_scale_sprite_sheet(scene->player->
            animated_sprite->sprites,
            (sfVector2f){.x = 244, .y = 250}, (sfVector2f){1, 1});
            window_data->current_scene = WORLD;
        }
    }
}

void pos_events(scenes_t *scene, window_t *window_data, char **grid)
{
    if (window_data->current_scene == WORLD && sfKeyboard_isKeyPressed(sfKeyZ)
    == sfTrue && scene->pos.y == 12 && scene->pos.x == 41) {
        window_data->current_scene = DUNGEON;
        place_scale_sprite_sheet(scene->player->
        animated_sprite->sprites,
        (sfVector2f){.x = 24 * DUNGEON_X + 3, .y = 24 * DUNGEON_Y - 8}, (sfVector2f){1, 1});
    }
    if (window_data->current_scene == DUNGEON && sfKeyboard_isKeyPressed(sfKeyS)
    == sfTrue && grid[(int)scene->pos.y][(int)scene->pos.x] == '7') {
        window_data->current_scene = WORLD;
        place_scale_sprite_sheet(scene->player->
        animated_sprite->sprites,
        (sfVector2f){.x = 964, .y = 253}, (sfVector2f){1, 1});
    }
    if (window_data->current_scene == DUNGEON)
        enemy_trigger(scene, window_data, grid);
}

void world_input(scenes_t *scene, window_t *window_data)
{
    char **grid = scene->GRID;
    static short i = 0;
    move_keys(scene, grid, &i);
    if (i == 0) {
        pos_events(scene, window_data, grid);
        event_keys(scene, window_data, grid);
    }
    if (scene->game_objects != NULL && scene->game_objects->npc != NULL) {
        for (int index = 0;scene->game_objects->npc[index]; index++)
            check_npc_world_event(scene, window_data, grid, index);
        check_npc_dungeon_event(scene, window_data, grid);
    }
}