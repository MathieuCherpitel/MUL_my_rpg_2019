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

sfVector2f get_position_hp_bar(int hp, int index, sfVector2f scale,
                                                        sfVector2f pos)
{
    sfVector2f result;
    int max = 200;
    int bar_lvl = (hp - max);

    result.y = ((18 + (13 * index)) * scale.y) + pos.y;
    while (index > 0) {
        max -= 100;
        if (bar_lvl > 0)
            hp -= bar_lvl;
        bar_lvl = (hp - max);
        index--;
    }
    result.x = (pos.x + ((100 - bar_lvl) * scale.x) - (120 * scale.x));
    return (result);
}

void display_hud_enemy(window_t *window_data, int hp, char *name,
                                                            sfVector2f pos)
{
    char *life = str_fusion("HP : ", my_itoa(hp));
    sfText *name_text = create_text(window_data->fonts[0], name,
                                                                sfWhite, 34);
    sfText *life_text = create_text(window_data->fonts[0], life,
                                                                sfBlack, 30);
    sfSprite **sprite = get_sprite_asset("hud_enemy.png",
                                        window_data->loaded_assets->player);
    sfVector2f scale = sfSprite_getScale(sprite[0]);

    for (int i = 1; i <= 3; i++) {
        sfSprite_setPosition(sprite[i],
                                get_position_hp_bar(hp, (i - 1), scale, pos));
        sfRenderWindow_drawSprite(window_data->render_window, sprite[i], NULL);
    }
    sfSprite_setPosition(sprite[0], (sfVector2f)
                                {.x = (pos.x - (125 * scale.x)), .y = pos.y});
    sfRenderWindow_drawSprite(window_data->render_window, sprite[0], NULL);
    sfText_setPosition(name_text, (sfVector2f)
                {.x = (pos.x - (118 * scale.x)), .y = (2 * scale.y) + pos.y});
    sfRenderWindow_drawText(window_data->render_window, name_text, NULL);
    sfText_setPosition(life_text, (sfVector2f)
                {.x = (pos.x - (118 * scale.x)), .y = (29 * scale.y) + pos.y});
    sfRenderWindow_drawText(window_data->render_window, life_text, NULL);
}
