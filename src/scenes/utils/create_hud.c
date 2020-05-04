/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_drawer
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "prototype.h"
#include "my_rpg.h"
#include "libmy.h"

void set_pos_text_hud(hud_player_t *hud, sfVector2f p, sfVector2f s)
{
    sfVector2f name = {.x = (0 + p.x), .y = ((s.y * 51) + p.y)};
    sfVector2f hp_text = {.x = ((s.x * 57) + p.x), .y = ((s.y * 33) + p.y)};
    sfVector2f mana_text = {.x = ((s.x * 57) + p.x), .y = ((s.y * 46) + p.y)};
    sfVector2f speed_text = {.x = ((s.x * 87) + p.x), .y = ((s.y * 21) + p.y)};
    sfVector2f att1_text =  {.x = ((s.x * 120) + p.x), .y = ((s.y * 5) + p.y)};
    sfVector2f att2_text = {.x = ((s.x * 120) + p.x), .y = ((s.y * 21) + p.y)};

    sfText_setPosition(hud->name, name);
    sfText_setPosition(hud->hp_text, hp_text);
    sfText_setPosition(hud->mana_text, mana_text);
    sfText_setPosition(hud->speed_text, speed_text);
    sfText_setPosition(hud->att1_text, att1_text);
    sfText_setPosition(hud->att2_text, att2_text);
}

void set_pos_sprite_hud(hud_player_t *hud, sfVector2f p, sfVector2f s)
{
    sfVector2f position = {.x = (0 + p.x), .y = (0 + p.y)};
    sfVector2f life_bar = {.x = ((s.x * 54) + p.x), .y = ((s.y * 35) + p.y)};
    sfVector2f mana_bar = {.x = ((s.x * 54) + p.x), .y = ((s.y * 48) + p.y)};
    sfVector2f st_weapon = {.x = ((s.x * 55) + p.x), .y = ((s.y * 2) + p.y)};
    sfVector2f nd_weapon = {.x = ((s.x * 71) + p.x), .y = ((s.y * 2) + p.y)};
    sfVector2f key_objt = {.x = ((s.x * 87) + p.x), .y = ((s.y * 2) + p.y)};
    sfVector2f pot_objt = {.x = ((s.x * 103) + p.x), .y = ((s.y * 2) + p.y)};

    sfSprite_setPosition(hud->hud_sprites[0], position);
    sfSprite_setPosition(hud->hud_sprites[1], position);
    for (int i = 0; i < 3; i++)
        sfSprite_setPosition(hud->bar_sprites[i], life_bar);
    for (int i = 3; i < 6; i++)
        sfSprite_setPosition(hud->bar_sprites[i], mana_bar);
    sfSprite_setPosition(hud->objects_sprites[0], st_weapon);
    sfSprite_setPosition(hud->objects_sprites[1], nd_weapon);
    sfSprite_setPosition(hud->objects_sprites[2], key_objt);
    sfSprite_setPosition(hud->objects_sprites[3], pot_objt);
    hud->hp_pos = life_bar;
    hud->mana_pos = mana_bar;
}

void create_text_hud(window_t *window_data, player_t *player)
{
    sfFont *font = window_data->fonts[0];
    char *hp = str_fusion("HP : ", my_itoa(player->hp));
    char *mana = str_fusion("MANA : ", my_itoa(player->mana));
    char *att1 = str_fusion("NORMAL ATT: ", my_itoa(player->normal_attack));
    char *att2 = str_fusion("SPECIAL ATT: ", my_itoa(player->special_attack));
    char *speed = str_fusion("SPEED : ", my_itoa(player->speed));

    player->hud->name = create_text(font, player->name, sfWhite, 30);
    player->hud->mana_text = create_text(font, mana, sfBlack, 30);
    player->hud->hp_text = create_text(font, hp, sfBlack, 30);
    player->hud->att1_text = create_text(font, att1, sfWhite, 20);
    player->hud->att2_text = create_text(font, att2, sfWhite, 20);
    player->hud->speed_text = create_text(font, speed, sfWhite, 20);
}

void create_sprite_hud
(window_t *data, player_t *player, int type, int gender)
{
    sfSprite **hud = get_sprite_asset("hud.png", data->loaded_assets->player);
    sfSprite **icon =
    get_sprite_asset("icon_player.png", data->loaded_assets->player);
    sfSprite **object =
    get_sprite_asset("objects.png", data->loaded_assets->objects);

    player->hud->hud_sprites[0] = hud[0];
    player->hud->hud_sprites[1] = icon[type + gender];
    player->hud->hud_sprites[2] = NULL;
    for (int i = 0; i < 7; i++)
        player->hud->bar_sprites[i] = hud[i + 1];
    player->hud->bar_sprites[7] = NULL;
    player->hud->objects_sprites[0] = object[(type * 2)];
    player->hud->objects_sprites[1] = object[(type * 2) + 1];
    player->hud->objects_sprites[2] = object[6];
    player->hud->objects_sprites[3] = object[7];
    player->hud->objects_sprites[4] = NULL;
    for (int i = 0; player->hud->objects_sprites[i] != NULL; i++)
        player->hud->active[i] = FALSE;
    player->hud->active[0] = TRUE;
}

void create_hud(window_t *window_data, player_t *player, int type, int gender)
{
    sfVector2f p = {.x = 0, .y = 0};
    sfVector2f s;

    create_sprite_hud(window_data, player, type, gender);
    create_text_hud(window_data, player);
    s = sfSprite_getScale(player->hud->hud_sprites[0]);
    set_pos_sprite_hud(player->hud, p, s);
    set_pos_text_hud(player->hud, p, s);
}