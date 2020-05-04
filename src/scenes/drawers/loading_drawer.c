/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_drawer
*/

#include "my_rpg.h"
#include "prototype.h"

int move_player(scenes_t *scene, window_t *window, int obj_count)
{
    int count = 0;

    obj_count++;
    if (obj_count > 5)
        obj_count = 0;
    count = 0;
    while (scene->game_objects->objects[obj_count]->animated_sprite->
                                                    sprites[count] != NULL) {
        sfSprite_setPosition(scene->game_objects->objects[obj_count]->
            animated_sprite->sprites[count], (sfVector2f){.x = 0, .y = 700});
        count++;
    }
    return (obj_count);
}

void display_loading_obj(scenes_t *scene, window_t *window_data)
{
    int count = 0;
    static int obj_count;
    int obj;
    static sfVector2f offset = {.x = 10, .y = 0};
    sfVector2f pos;

    while (scene->game_objects->objects[obj_count]->animated_sprite->
                                                sprites[count] != NULL) {
        sfSprite_move(scene->game_objects->objects[obj_count]->
                                        animated_sprite->sprites[count], offset);
        count++;
    }
    pos = sfSprite_getPosition(scene->game_objects->objects[obj_count]->
                                                    animated_sprite->sprites[0]);
    obj = obj_count;
    if (pos.x > 1920)
        obj = move_player(scene, window_data, obj);
    obj_count = obj;
    display_animated_sprite(window_data, scene->game_objects->
                                    objects[obj_count]->animated_sprite, RUN);    
}

void loading_drawer(scenes_t *scene, window_t *window_data)
{
    display_background(scene, window_data);
    display_text(scene, window_data);
    display_loading_obj(scene, window_data);
}
