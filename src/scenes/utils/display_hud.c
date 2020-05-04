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

sfSprite *move_bar(sfSprite **sprites, sfVector2f pos, int index, int number)
{
    sfVector2f scale = sfSprite_getScale(sprites[index]);
    sfVector2f tmp = pos;

    if (number >= 66) {
        tmp.x -= ((scale.x * 100) - (scale.x * number));
        sfSprite_setPosition(sprites[index], tmp);
        return (sprites[index]);
    }
    index++;
    if (number >= 33 && number < 66) {
        tmp.x -= ((scale.x * 67) - (scale.x * number));
        sfSprite_setPosition(sprites[index], tmp);
        return (sprites[index]);
    }
    index++;
    tmp.x -= ((scale.x * 34) - (scale.x * number));
    sfSprite_setPosition(sprites[index], tmp);
    return (sprites[index]);
}

void display_life(player_t *player, window_t *window_data)
{
    char *hp_str = str_fusion("HP : ", my_itoa(player->hp));
    char *mana_str = str_fusion("MANA : ", my_itoa(player->mana));
    sfSprite *hp_bar = move_bar(player->hud->bar_sprites, player->hud->hp_pos,
                                                                0, player->hp);
    sfSprite *mana_bar = move_bar(player->hud->bar_sprites,
                                    player->hud->mana_pos, 3, player->mana);

    sfText_setString(player->hud->hp_text, hp_str);
    sfText_setString(player->hud->mana_text, mana_str);
    sfRenderWindow_drawSprite(window_data->render_window, hp_bar, NULL);
    sfRenderWindow_drawSprite(window_data->render_window, mana_bar, NULL);
    sfRenderWindow_drawText(window_data->render_window,
                                                player->hud->hp_text, NULL);
    sfRenderWindow_drawText(window_data->render_window,
                                                player->hud->mana_text, NULL);
}

void display_hud(player_t *player, window_t *w)
{
    char *att1 = str_fusion("NORMAL ATT: ", my_itoa(player->normal_attack));
    char *att2 = str_fusion("SPECIAL ATT: ", my_itoa(player->special_attack));
    char *speed_str = str_fusion("SPEED : ", my_itoa(player->speed));

    display_life(player, w);
    for (int i = 0; player->hud->hud_sprites[i] != NULL; i++)
        sfRenderWindow_drawSprite
        (w->render_window,player->hud->hud_sprites[i], NULL);
    for (int i = 0; player->hud->objects_sprites[i] != NULL; i++) {
        if (player->hud->active[i] == TRUE)
            sfRenderWindow_drawSprite
            (w->render_window, player->hud->objects_sprites[i], NULL);
    }
    sfText_setString(player->hud->att1_text, att1);
    sfText_setString(player->hud->att2_text, att2);
    sfText_setString(player->hud->speed_text, speed_str);
    sfRenderWindow_drawText(w->render_window, player->hud->att1_text, NULL);
    sfRenderWindow_drawText(w->render_window, player->hud->att2_text, NULL);
    sfRenderWindow_drawText(w->render_window, player->hud->speed_text, NULL);
    sfRenderWindow_drawText(w->render_window, player->hud->name, NULL);
}