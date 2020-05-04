/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#include <stdlib.h>
#include "prototype.h"
#include "my_rpg.h"
#include "struct.h"

void init_screen_size(window_t *window)
{
    window->screen_size = malloc(sizeof(sfVector2u) * 3);
    window->screen_size[0].x = 1920;
    window->screen_size[0].y = 1080;
    window->screen_size[1].x = 800;
    window->screen_size[1].y = 600;
}

window_t *init_render_window(void)
{
    window_t *window = malloc(sizeof(window_t));
    sfVideoMode video_mode = {WIDTH, HEIGHT, 32};

    if (window == NULL)
        return (NULL);
    window->render_window = sfRenderWindow_create(video_mode,
    "my rpg", sfResize | sfClose, NULL);
    if (window->render_window == NULL)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window->render_window, 60);
    if (window->render_window == NULL)
        return (NULL);
    window->view = sfView_createFromRect((sfFloatRect){.width = 1920,
                                                    .height = 1080});
    window->anim = sfClock_create();
    window->current_scene = LOADING_SCENE;
    window->current_size = 0;
    window->clock = sfClock_create();
    init_screen_size(window);
    return (window);
}

game_t *allocate_game_data(void)
{
    game_t *game_data = malloc(sizeof(game_t));

    if (game_data == NULL)
        return (NULL);
    game_data->window_data = init_render_window();
    if (game_data->window_data == NULL)
        return (NULL);
    game_data->scenes = malloc(sizeof(scenes_t *) * SCENE_NUMBER);
    if (game_data->scenes == NULL)
        return (NULL);
    return (game_data);
}

int my_rpg(void)
{
    game_t *game_data = allocate_game_data();
    int return_value = 0;

    if (game_data == NULL)
        return (ERR);
    game_data->window_data = load_assets(game_data);
    if (game_data->window_data == NULL)
        return (ERR);
    game_data = create_scenes(game_data);
    if (game_data == NULL)
        return (ERR);
    return_value = game_loop(game_data);
    return (return_value);
}