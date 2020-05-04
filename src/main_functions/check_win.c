/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_win
*/

#include "prototype.h"
#include "my_rpg.h"

void check_close(window_t *window_data)
{
    while (sfRenderWindow_pollEvent
                        (window_data->render_window, &window_data->event)) {
        if (window_data->event.type == sfEvtClosed) {
            sfRenderWindow_close(window_data->render_window);
        }
    }
}

void check_win(game_t *game_data)
{
    if (game_data->window_data->enemies[0]->status == DEAD)
        game_data->win = TRUE;
}

void display_win_screen(game_t *game_data)
{
    sfSprite *background = get_background_asset("victory_screen.png",
                        game_data->window_data->loaded_assets->background);

    while (sfRenderWindow_isOpen(game_data->window_data->render_window)) {
        check_close(game_data->window_data);
        sfRenderWindow_drawSprite(game_data->window_data->render_window,
                                                        background, NULL);
        sfRenderWindow_display(game_data->window_data->render_window);
    }
}