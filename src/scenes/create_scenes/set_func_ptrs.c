/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_func_ptrs
*/

#include "my_rpg.h"
#include "prototype.h"

scenes_t *none(__attribute__((unused)) scenes_t *scene,
                        __attribute__((unused)) window_t *window_data)
{
    return (scene);
}

void set_constructors(game_t *game_data)
{
    game_data->scenes[LOADING_SCENE]->constructor = loading_constructor;
    game_data->scenes[WORLD]->constructor = world_constructor;
    game_data->scenes[CHARACTER_SCENE]->constructor = character_constructor;
    game_data->scenes[HOUSE]->constructor = house_constructor;
    game_data->scenes[DUNGEON]->constructor = dungeon_constructor;
    game_data->scenes[FIGHT]->constructor = none;
}

void set_drawers(game_t *game_data)
{
    game_data->scenes[LOADING_SCENE]->drawer = loading_drawer;
    game_data->scenes[WORLD]->drawer = world_drawer;
    game_data->scenes[CHARACTER_SCENE]->drawer = character_drawer;
    game_data->scenes[HOUSE]->drawer = world_drawer;
    game_data->scenes[DUNGEON]->drawer = world_drawer;
    game_data->scenes[FIGHT]->drawer = fight_drawer;
}

void set_input_managers(game_t *game_data)
{
    game_data->scenes[LOADING_SCENE]->input_method = loading_input;
    game_data->scenes[WORLD]->input_method = world_input;
    game_data->scenes[CHARACTER_SCENE]->input_method = character_input;
    game_data->scenes[HOUSE]->input_method = world_input;
    game_data->scenes[DUNGEON]->input_method = world_input;
    game_data->scenes[FIGHT]->input_method = fight_input;
}

void set_function_pointers(game_t *game_data)
{
    set_constructors(game_data);
    set_drawers(game_data);
    set_input_managers(game_data);
}
