/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_constructor
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "prototype.h"

enemy_t *allocate_enemy_sprite(enemy_t *enemy)
{
    int sprite_count = 8;    

    enemy->animated_sprite = malloc(sizeof(animated_sprites_t));
    enemy->animated_sprite->even = FALSE;
    enemy->animated_sprite->odd = FALSE;
    enemy->animated_sprite->sprite_count = 0;
    enemy->animated_sprite->sprites = malloc(sizeof(sfSprite *) *
                                                (sprite_count + 1));
    if (enemy->animated_sprite->sprites == NULL)
        return (NULL);
    return (enemy);
}

enemy_t **allocate_enemies(void)
{
    int count = 0;
    enemy_t **enemy_arr = malloc(sizeof(enemy_t *) * (ENEMY_COUNT + 1));

    while (count < ENEMY_COUNT) {
        enemy_arr[count] = malloc(sizeof(enemy_t));
        if (enemy_arr[count] == NULL)
            return (NULL);
        enemy_arr[count] = allocate_enemy_sprite(enemy_arr[count]);
        if (enemy_arr[count] == NULL)
            return (NULL);
        count++;
    }
    enemy_arr[count] = NULL;
    return (enemy_arr);
}

game_objects_t *create_fight_game_obj(window_t *window_data)
{
    game_objects_t *game_obj = malloc(sizeof(game_objects_t));

    if (game_obj == NULL)
        return (NULL);
    game_obj->enemies = allocate_enemies();
    if (game_obj->enemies == NULL)
        return (NULL);
    game_obj->enemies = create_all_enemies(game_obj->enemies, window_data);
    if (game_obj->enemies == NULL)
        return (NULL);
    return (game_obj);
}

scenes_t *fight_constructor(scenes_t *scene, window_t *window_data)
{
    scene->background = get_background_asset("dungeon_background.jpg",
                                    window_data->loaded_assets->background);
    sfSprite_setPosition(scene->background, (sfVector2f){.x = 0, .y = 0});
  
    scene->game_objects = malloc(sizeof(game_objects_t));
    scene->game_objects->enemies = window_data->enemies;
    scene->current_enemy = window_data->current_enemy;

    scene->text = create_scene_text(window_data);
    scene->special_text = create_special_text(window_data);
    scene->music = window_data->musics[ARRIVAL];
    scene->music_start = FALSE;
    scene->buttons = create_fight_scene_buttons(scene, window_data);
    if (scene->game_objects == NULL)
        return (NULL);
    return (scene);
}
