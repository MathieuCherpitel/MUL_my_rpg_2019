/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_loop
*/

#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

void create_enemies_in_window_data(window_t *window_data)
{
    int count = 0;

    window_data->enemies = allocate_enemies();
    window_data->enemies = create_all_enemies(window_data->enemies,
                                                        window_data);
    window_data->current_enemy = window_data->enemies[3];
    while (count <ENEMY_COUNT) {
        if (my_strcmp(window_data->enemies[count]->name, "big_demon") == 0
        || my_strcmp(window_data->enemies[count]->name, "big_zombie") == 0
        || my_strcmp(window_data->enemies[count]->name, "ogre") == 0) {
            place_scale_sprite_sheet
            (window_data->enemies[count]->animated_sprite->sprites,
            (sfVector2f){.x = 1400, .y = 300}, (sfVector2f){.x = 15, .y = 15});
        }
        else
            place_scale_sprite_sheet
            (window_data->enemies[count]->animated_sprite->sprites,
            (sfVector2f){.x = 1400, .y = 600}, (sfVector2f){.x = 15, .y = 15});
        count++;
    }
}

void check_sprite_button(buttons_t *button, sfVector2f mouse_position,
                                            game_t *game_data, void *scene_ptr)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->sprite_to_draw);

    bounds.height -= 5;
    bounds.top += 53;
    if (sfFloatRect_contains
        (&bounds, mouse_position.x, mouse_position.y) == sfTrue) {
        sfText_setColor(button->text[0], (sfColor){255, 255, 255, 150});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            button->selected = TRUE;
    }
    else
        sfText_setColor(button->text[0], (sfColor){255, 255, 255, 150});
    if (game_data->window_data->event.type == sfEvtMouseButtonReleased &&
                                                    button->selected == TRUE) {
        sfText_setColor(button->text[0], (sfColor){255, 255, 255, 255});
        button->callback(scene_ptr, game_data->window_data);
        button->selected = FALSE;
    }
}

void check_fight_button(scenes_t *scene, game_t *game_data, void *scene_ptr)
{
    int count = 0;
    sfVector2i mouse_pos;
    sfVector2f pos;

    while (scene->buttons[count] != NULL) {
        if (scene->player->mana < 40 && (count == 1 || count == 2))
            count++;
        else {
            mouse_pos = sfMouse_getPosition(NULL);
            pos = (sfVector2f){mouse_pos.x, mouse_pos.y};
            check_sprite_button(scene->buttons[count], pos, game_data,
                                                                    scene_ptr);
            count++;
        }
    }
}

void specific_scenes_managment(game_t *game_data, int scene_index,
                                                            void *scene_ptr)
{
    static int first_time = TRUE;

    if (scene_index == WORLD && first_time == TRUE) {
        game_data->scenes[FIGHT] = fight_constructor
                            (game_data->scenes[FIGHT], game_data->window_data);
        game_data->window_data->enemies = game_data->scenes
                                                [FIGHT]->game_objects->enemies;
        first_time = FALSE;
    }
    if (scene_index == FIGHT) {
        game_data->scenes[FIGHT]->current_enemy = game_data->
                                                    window_data->current_enemy;
        check_fight_button(game_data->scenes[scene_index],
                                                        game_data, scene_ptr);
    }
}

int game_loop(game_t *game_data)
{
    int scene_index = LOADING_SCENE;
    void *scene_ptr;

    create_enemies_in_window_data(game_data->window_data);
    game_data->window_data->ptr = game_data;
    game_data->win = FALSE;
    while (sfRenderWindow_isOpen
        (game_data->window_data->render_window) && game_data->win == FALSE) {
        check_win(game_data);
        scene_ptr = game_data->scenes[scene_index];
        check_event(game_data->window_data, game_data->scenes[scene_index],
                                                                scene_index);
        game_data->scenes[scene_index]->drawer(game_data->scenes[scene_index],
                                                    game_data->window_data);
        specific_scenes_managment(game_data, scene_index, scene_ptr);
        scene_index = game_data->window_data->current_scene;
        sfRenderWindow_display(game_data->window_data->render_window);
    }
    display_win_screen(game_data);
    return (SUCCESS);
}
