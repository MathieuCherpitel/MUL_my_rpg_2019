/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_player_attacks
*/

#include <stdlib.h>
#include "prototype.h"
#include "my_rpg.h"

attack_t *init_attack_normal(void)
{
    attack_t *attack = malloc(sizeof(attack_t));

    attack->name = "Normal";
    attack->damage = 20;
    return (attack);
}

attack_t *init_attack_spe(void)
{
    attack_t *attack = malloc(sizeof(attack_t));

    attack->name = "Queue de fer";
    attack->damage = 50;
    return (attack);
}

attack_t *init_attack_heal(void)
{
    attack_t *attack = malloc(sizeof(attack_t));

    attack->name = "Heal";
    attack->damage = 150;
    return (attack);
}