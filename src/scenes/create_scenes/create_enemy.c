/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_enemy
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "prototype.h"

animated_sprites_t *set_animated_sprite(animated_sprites_t *sprites)
{
    sprites->even = FALSE;
    sprites->odd = FALSE;
    sprites->sprite_count = 0;
    return (sprites);
}

attack_t *create_attack(char *name, int damage)
{
    attack_t *attack = malloc(sizeof(attack_t));

    if (attack == NULL)
        return (NULL);
    attack->name = name;
    attack->damage = damage;
    return (attack);
}

enemy_t *create_easy_enemy(enemy_t *enemy, sfSprite **sprite, char *name)
{
    enemy->attacks = malloc(sizeof(attack_t *) * (2));
    if (enemy->attacks == NULL)
        return (NULL);
    enemy->attacks[0] = create_attack("small hit", 1);
    enemy->attacks[1] = create_attack("hit", 5);
    if (enemy->attacks[0] == NULL || enemy->attacks[1] == NULL)
        return (NULL);
    enemy->name = name;
    enemy->animated_sprite->sprites = sprite;
    enemy->animated_sprite = set_animated_sprite(enemy->animated_sprite);
    enemy->hp = 50;
    enemy->status = ALIVE;
    return (enemy);
}

enemy_t *create_medium_enemy(enemy_t *enemy, sfSprite **sprite, char *name)
{
    enemy->attacks = malloc(sizeof(attack_t *) * (2));
    if (enemy->attacks == NULL)
        return (NULL);
    enemy->attacks[0] = create_attack("hit", 5);
    enemy->attacks[1] = create_attack("big hit", 15);
    if (enemy->attacks[0] == NULL || enemy->attacks[1] == NULL)
        return (NULL);
    enemy->name = name;
    enemy->animated_sprite->sprites = sprite;
    enemy->animated_sprite = set_animated_sprite(enemy->animated_sprite);
    enemy->hp = 150;
    enemy->status = ALIVE;
    return (enemy);
}

enemy_t *create_boss_enemy(enemy_t *enemy, sfSprite **sprite, char *name)
{
    enemy->attacks = malloc(sizeof(attack_t *) * (2));
    if (enemy->attacks == NULL)
        return (NULL);
    enemy->attacks[0] = create_attack("hit", 5);
    enemy->attacks[1] = create_attack("big hit", 15);
    if (enemy->attacks[0] == NULL || enemy->attacks[1] == NULL)
        return (NULL);
    enemy->name = name;
    enemy->animated_sprite->sprites = sprite;
    enemy->animated_sprite = set_animated_sprite(enemy->animated_sprite);
    enemy->hp = 300;
    enemy->status = ALIVE;
    return (enemy);
}