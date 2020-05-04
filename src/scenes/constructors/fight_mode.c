/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_mode
*/

#include "prototype.h"
#include "libmy.h"
#include "my_rpg.h"

void respawn_player(scenes_t *scene, window_t *window_data)
{
    game_t *game_data = window_data->ptr;

    sfMusic_pause(scene->music);
    scene->music_start = FALSE;
    game_data->scenes[DUNGEON]->pos.x = DUNGEON_X;
    game_data->scenes[DUNGEON]->pos.y = DUNGEON_Y;
    sfView_setCenter(game_data->scenes[DUNGEON]->view, (sfVector2f)
            {.x = (DUNGEON_X * 24) + 12, .y = (DUNGEON_Y * 24) + 12});
    move(game_data->scenes[WORLD], game_data->scenes[WORLD]->view, 0, -30);
    game_data->scenes[WORLD]->player->hp = 100;
    place_scale_sprite_sheet(scene->player->
    animated_sprite->sprites,
    (sfVector2f){.x = 169, .y = 230}, (sfVector2f){1, 1});
    window_data->current_scene = HOUSE;
}

void enemy_turn(scenes_t *scene, window_t *window_data)
{
    static int mana = 0;

    if (mana == 3) {
        sfText_setString(scene->special_text[0],
                                    scene->current_enemy->attacks[1]->name);
        scene->player->hp -= scene->current_enemy->attacks[1]->damage;
        mana = 0;
    }
    else {
        sfText_setString(scene->special_text[0],
                                    scene->current_enemy->attacks[1]->name);
        scene->player->hp -= scene->current_enemy->attacks[0]->damage;
        mana++; 
    }
    if (scene->player->hp <= 0)
        respawn_player(scene, window_data);
}

void normal_attack(void *scene_ptr, window_t *window_data)
{
    scenes_t *scene = scene_ptr;

    scene->current_enemy->hp -= scene->player->normal_attack;
    if (scene->player->mana < 100)
        scene->player->mana += 20;
    enemy_turn(scene, window_data);
    if (scene->current_enemy->hp <= 0) {
        scene->current_enemy->status = DEAD;
        window_data->current_enemy->status = DEAD;
        window_data->current_scene = DUNGEON;
        sfRenderWindow_clear(window_data->render_window, sfBlack);
        sfMusic_pause(scene->music);
        scene->music_start = FALSE;
    }
}

void special_attack(void *scene_ptr, window_t *window_data)
{
    scenes_t *scene = scene_ptr;

    scene->current_enemy->hp -= scene->player->normal_attack;
    scene->player->mana -= 40;
    sfText_setString(scene->special_text[0],
                                scene->player->attacks[1]->name);
    enemy_turn(scene, window_data);
    if (scene->current_enemy->hp <= 0) {
        scene->current_enemy->status = DEAD;
        window_data->current_enemy->status = DEAD;
        window_data->current_scene = DUNGEON;
        sfRenderWindow_clear(window_data->render_window, sfBlack);
        sfMusic_pause(scene->music);
        scene->music_start = FALSE;
    }
}

void heal(void *scene_ptr, window_t *window_data)
{
    scenes_t *scene = scene_ptr;

    scene->player->hp += scene->player->heal;
    scene->player->mana -= 40;
    sfText_setString(scene->special_text[0],
                                scene->player->attacks[2]->name);
    enemy_turn(scene, window_data);
}