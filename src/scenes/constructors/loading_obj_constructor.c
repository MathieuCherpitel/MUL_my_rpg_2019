/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_obj_constructor
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "prototype.h"

sfSprite **init_sprite_pos(sfSprite **sprite)
{
    int count = 0;

    while (sprite[count] != NULL) {
        sfSprite_scale(sprite[count], (sfVector2f){.x = 1.7, .y = 1.7});
        sfSprite_setPosition(sprite[count], (sfVector2f){.x = 0, .y = 700});
        count++;
    }
    return (sprite);
}

object_t **set_obj_sprites(object_t **ar, window_t *window_data)
{
    loaded_sprites_t **player = window_data->loaded_assets->player;
    sfVector2f pos = {.x = 0, .y = 700};
    sfVector2f scale = {.x = 1.7, .y = 1.7};

    ar[0]->animated_sprite->sprites = get_sprite_asset("elf_m.png", player);
    place_scale_sprite_sheet(ar[0]->animated_sprite->sprites, pos, scale);
    ar[1]->animated_sprite->sprites = get_sprite_asset("elf_w.png", player);
    place_scale_sprite_sheet(ar[1]->animated_sprite->sprites, pos, scale);
    ar[2]->animated_sprite->sprites = get_sprite_asset("knight_m.png", player);
    place_scale_sprite_sheet(ar[2]->animated_sprite->sprites, pos, scale);
    ar[3]->animated_sprite->sprites = get_sprite_asset
                                                    ("knight_w.png", player);
    place_scale_sprite_sheet(ar[3]->animated_sprite->sprites, pos, scale);
    ar[4]->animated_sprite->sprites = get_sprite_asset
                                                    ("wizzard_m.png", player);
    place_scale_sprite_sheet(ar[4]->animated_sprite->sprites, pos, scale);
    ar[5]->animated_sprite->sprites = get_sprite_asset
                                                    ("wizzard_w.png", player);
    place_scale_sprite_sheet(ar[5]->animated_sprite->sprites, pos, scale);
    return (ar);
}

object_t **allocate_sprites(object_t **obj_arr)
{
    int count = 0;
    int sprite_count = 9;

    while (obj_arr[count] != NULL) {
        obj_arr[count]->hitbox = NULL,
        obj_arr[count]->object_interaction = NULL;
        obj_arr[count]->texture = NULL;
        obj_arr[count]->animated_sprite = malloc(sizeof(animated_sprites_t));
        if (obj_arr[count]->animated_sprite == NULL)
            return (NULL);
        obj_arr[count]->animated_sprite->even = FALSE;
        obj_arr[count]->animated_sprite->odd = FALSE;
        obj_arr[count]->animated_sprite->sprite_count = 0;
        obj_arr[count]->animated_sprite->sprites = malloc(sizeof(sfSprite *) * 
                                                        (sprite_count + 1));
        if (obj_arr[count]->animated_sprite->sprites == NULL)
            return (NULL);
        count++;
    }
    return (obj_arr);
}

object_t **create_loading_obj(scenes_t *scene, window_t *window_data)
{
    int obj_count = 6;
    object_t **obj_arr = scene->game_objects->objects;

    obj_arr = allocate_obj(obj_count);
    if (obj_arr == NULL)
        return (NULL);
    obj_arr = allocate_sprites(obj_arr);
    if (obj_arr == NULL)
        return (NULL);
    obj_arr = set_obj_sprites(obj_arr, window_data);
    if (obj_arr == NULL)
        return (NULL);
    return (obj_arr);
}