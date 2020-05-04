/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_enemy_dungeon_scene
*/

#include <stdlib.h>
#include "prototype.h"
#include "my_rpg.h"

enemy_t **allocate_dungeon_enemies(scenes_t *scene)
{
    int enemy_count = 12;
    int count = 0;

    scene->game_objects->enemies =
    malloc(sizeof(enemy_t *) * (enemy_count + 1));
    if (scene->game_objects->enemies == NULL)
        return (NULL);
    while (count < enemy_count) {
        scene->game_objects->enemies[count] = malloc(sizeof(enemy_t));
        if (scene->game_objects->enemies[count] == NULL)
            return (NULL);
        count++;
    }
    scene->game_objects->enemies[count] = NULL;
    return (scene->game_objects->enemies);
}

void set_sprite(sfSprite **sprite, sfVector2f pos)
{
    int count = 0;
    sfVector2f sprite_pos = (sfVector2f){.x = pos.x * 24, .y = pos.y * 24};

    while (sprite[count] != NULL) {
        sfSprite_setOrigin(sprite[count], (sfVector2f){.x = 12, .y = 12});
        sfSprite_setPosition(sprite[count], sprite_pos);
        count++;
    }
}

sfSprite **copy_sprite(char *name, window_t *window_data)
{
    sfSprite **sprite =
    get_sprite_asset(name, window_data->loaded_assets->enemy);
    sfSprite **copy = malloc(sizeof(sfSprite *) * 9);
    int count = 0;

    while (count < 8) {
        copy[count] = sfSprite_copy(sprite[count]);
        sfSprite_scale(copy[count], (sfVector2f){.x = 2.5, .y = 2.5});
        count++;
    }
    copy[8] = NULL;
    return (copy);
}

enemy_t *create_enemy_type
(enemy_t *enemy, sfSprite **sprite, char *name, int type)
{
    switch (type) {
    case BOSS:
        enemy = create_boss_enemy(enemy, sprite, name);
        break;
    case MEDIUM:
        enemy = create_medium_enemy(enemy, sprite, name);
        break;
    case EASY:
        enemy = create_easy_enemy(enemy, sprite, name);
        break;
    }
    return (enemy);
}

enemy_t *create_enemy
(enemy_t *enemy, window_t *window_data, char *name, int type)
{
    char *complete_name = str_fusion(name, ".png");

    enemy->animated_sprite = malloc(sizeof(animated_sprites_t));
    enemy->animated_sprite->sprites = malloc(sizeof(sfSprite * ) * 9);
    if (enemy->animated_sprite == NULL ||
    enemy->animated_sprite->sprites == NULL)
        return (NULL);
    enemy = create_enemy_type(enemy,
    copy_sprite(complete_name, window_data), name, type);
    return (enemy);
}