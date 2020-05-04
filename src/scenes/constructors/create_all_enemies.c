/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_all_enemies
*/

#include <stdio.h>
#include "libmy.h"
#include "my_rpg.h"
#include "prototype.h"

char *set_enemy_name(char *asset_name)
{
    char *name = my_strdup(asset_name);
    int count = 0;

    if (name == NULL)
        return (NULL);
    while (name[count] != '.')
        count++;
    name[count] = 0;
    return (name);
}

int create_all_boss(enemy_t **enemies, window_t *window_data)
{
    char *boss[] = {"big_demon.png", "big_zombie.png", "ogre.png", NULL};
    int i = 0;
    char *name;
    int enemy_count = 0;

    while (boss[i] != NULL) {
        name = set_enemy_name(boss[i]);
        enemies[enemy_count] = create_boss_enemy(enemies[enemy_count],
        get_sprite_asset(boss[i], window_data->loaded_assets->enemy), name);
        if (enemies[enemy_count] == NULL)
            return (ERR);
        i++;
        enemies[enemy_count]->animated_sprite->sprites[8] = NULL;
        enemies[enemy_count]->status = ALIVE;
        enemy_count++;
    }
    return (enemy_count);
}

int create_all_medium_enemies
(enemy_t **enemies, window_t *window_data, int enemy_count)
{
    char *medium[] = {"ice_zombie.png", "masked_orc.png", "necromancer.png",
    "orc_shaman.png", "orc_warrior.png", NULL};
    int i = 0;
    char *name;

    while (medium[i] != NULL) {
        name = set_enemy_name(medium[i]);
        enemies[enemy_count] = create_medium_enemy(enemies[enemy_count],
        get_sprite_asset(medium[i], window_data->loaded_assets->enemy), name);
        if (enemies[enemy_count] == NULL)
            return (ERR);
        i++;
        enemies[enemy_count]->animated_sprite->sprites[8] = NULL;
        enemies[enemy_count]->status = ALIVE;
        enemy_count++;
    }
    return (enemy_count);
}

int create_all_easy_enemies
(enemy_t **enemies, window_t *window_data, int enemy_count)
{
    char *easy[] = {"goblin.png", "imp.png", "muddy.png", "skelet.png",
    "swamp.png", "zombie.png", NULL};
    int i = 0;
    char *name;

    while (easy[i] != NULL) {
        name = set_enemy_name(easy[i]);
        enemies[enemy_count] = create_easy_enemy(enemies[enemy_count],
        get_sprite_asset(easy[i], window_data->loaded_assets->enemy), name);
        if (enemies[enemy_count] == NULL)
            return (ERR);
        i++;
        enemies[enemy_count]->animated_sprite->sprites[8] = NULL;
        enemies[enemy_count]->status = ALIVE;
        enemy_count++;
    }
    return (enemy_count);
}

enemy_t **create_all_enemies(enemy_t **enemies, window_t *window_data)
{
    my_putstr("\ncreating enemies\n");
    int enemy_count = create_all_boss(enemies, window_data);

    if (enemy_count == ERR)
        return (NULL);
    enemy_count = create_all_easy_enemies(enemies, window_data, enemy_count);
    if (enemy_count == ERR)
        return (NULL);
    enemy_count = create_all_medium_enemies(enemies, window_data, enemy_count);
    if (enemy_count == ERR)
        return (NULL);
    return (enemies);
}