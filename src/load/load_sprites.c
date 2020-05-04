/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_sprites
*/

#include <dirent.h>
#include <stdlib.h>
#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

int get_tab_len(char **tab)
{
    int count = 0;

    while (tab[count] != NULL)
        count++;
    return (count);
}

char *get_asset_name(char *sprite_path)
{
    char *tmp = my_strdup(sprite_path);
    void *save_tmp = tmp;
    int pos = my_strlen(sprite_path);
    int count = 0;
    char *name;

    while (tmp[pos] != '/')
        pos--;
    name = malloc(sizeof(char) * ((my_strlen(tmp) - pos) + 1));
    if (name == NULL)
        return (NULL);
    while (count < pos) {
        tmp++;
        count++;
    }
    name = my_strdup(++tmp);
    free(save_tmp);
    return (name);
}

window_t *load_all(window_t *window_data, char **folder_to_open)
{
    window_data->loaded_assets->objects = load_object
        (get_assets(folder_to_open[0]), window_data->loaded_assets->objects);
    window_data->loaded_assets->UI = load_ui
    (get_assets(folder_to_open[1]), window_data->loaded_assets->UI);
    window_data->loaded_assets->player = load_players
    (get_assets(folder_to_open[2]), window_data->loaded_assets->player);
    window_data->loaded_assets->background = load_any_sprites
    (get_assets(folder_to_open[3]), window_data->loaded_assets->background);
    window_data->loaded_assets->enemy = load_entities
    (get_assets(folder_to_open[4]), window_data->loaded_assets->enemy);
    window_data->loaded_assets->npc = load_npc
    (get_assets(folder_to_open[5]), window_data->loaded_assets->npc);
    if (window_data->loaded_assets->enemy == NULL
    || window_data->loaded_assets->npc == NULL
    || window_data->loaded_assets->objects == NULL
    || window_data->loaded_assets->player == NULL
    || window_data->loaded_assets->UI == NULL)
         return (NULL);
    return (window_data);
}

window_t *load_sprites(window_t *window_data)
{
    char *folders_to_open[] = {"rpg_assets/objects", "rpg_assets/UI",
    "rpg_assets/player", "rpg_assets/backgrounds", "rpg_assets/enemies",
    "rpg_assets/npc_s"};

    window_data->loaded_assets = malloc(sizeof(loaded_assets_t));
    if (window_data->loaded_assets == NULL)
        return (NULL);
    window_data = load_all(window_data, folders_to_open);
    if (window_data == NULL)
        return (NULL);
    return (window_data);
}
