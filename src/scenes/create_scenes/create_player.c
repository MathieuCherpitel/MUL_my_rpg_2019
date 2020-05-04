/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_player
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "prototype.h"

player_t *set_player_attacks(player_t *player)
{
    int attack_count = 3;

    player->attacks = malloc(sizeof(attack_t *) * (attack_count));
    if (player->attacks == NULL)
        return (NULL);
    player->attacks[0] = init_attack_normal();
    player->attacks[1] = init_attack_spe();
    player->attacks[2] = init_attack_heal();
    player->turn = 1;
    return (player);
}

player_t *set_player_sprites(player_t *player)
{
    player->inventory = malloc(sizeof(inventory_t));
    player->animated_sprite = malloc(sizeof(animated_sprites_t));
    player->animated_sprite->sprite_count = 0;
    player->animated_sprite->odd = FALSE;
    player->animated_sprite->even = FALSE;
    if (player->inventory == NULL || player->animated_sprite == NULL)
        return (NULL);
    return (player);
}

player_t *set_player_values(player_t *player)
{
    player->name = NULL;
    player->hp = 100;
    player->mana = 0;
    player->xp = 0;
    player->speed = 1;
    player->normal_attack = 20;
    player->special_attack = 30;
    player->heal = 20;
    player->quest_obj_1 = FALSE;
    player->hitbox = 0;
    player->sounds = NULL;
    return (player);
}

player_t *set_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return (NULL);
    player = set_player_values(player);
    player->hud = set_hud();
    player = set_player_attacks(player);
    if (player->attacks == NULL)
        return (NULL);
    player = set_player_sprites(player);
    if (player == NULL)
        return (NULL);
    return (player);
}