/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <dirent.h>
#include "struct.h"

/*
** src/load
*/
void set_sprite(sfSprite **sprite, sfVector2f pos);
loaded_sprites_t **load_ui(char **assets_path, loaded_sprites_t **players);

// get assets
char **get_assets(char *folder_name);
char **get_assets_names(char **assets_names, char *folder_name);
int get_file_count(char *folder_name);
sfSprite *get_any_asset(char *name, loaded_sprites_t **category);

// load any sprites
loaded_sprites_t **load_any_sprites(char **assets_path,
                                                loaded_sprites_t **sprites);

// load assets
window_t *load_assets(game_t *game_data);
window_t *load(window_t *window_data);

// load entities
loaded_sprites_t **load_entities(char **assets_path,
                                                loaded_sprites_t **entities);
sfSprite **load_entity_sprite_sheet(sfTexture *texture, char *name);
loaded_sprites_t **load_entities_loop(char **assets_path,
                                                loaded_sprites_t **entities);
loaded_sprites_t **load_object(char **assets_path,
                                                loaded_sprites_t **sprites);

// load players
loaded_sprites_t **load_players(char **assets_path,
                                                loaded_sprites_t **players);
sfSprite **load_player_sprites(loaded_sprites_t *players);
sfSprite **load_player_sprite_sheet(sfTexture *texture);
loaded_sprites_t **load_player_loop(char **assets_path,
                                                loaded_sprites_t **players);

// load sprites
window_t *load_sprites(window_t *window_data);
window_t *load_all(window_t *window_data, char **folder_to_open);
char *get_asset_name(char *sprite_path);
int get_tab_len(char **tab);

loaded_sprites_t **load_npc(char **assets_path,loaded_sprites_t **players);
/*
**  src/event
*/

// check event
void check_event(window_t *window_data, scenes_t *scenes, int scene_index);


/*
** src/main_functions
*/
void move_every_sprite(sfSprite **sprites, sfVector2f pos);
// rpg
int my_rpg(void);
game_t *allocate_game_data(void);
window_t *init_render_window(void);

// game loop
int game_loop(game_t *game_data);
void check_win(game_t *game_data);
void display_win_screen(game_t *game_data);

/*
**  src/scenes/constructors
*/

// constructor
scenes_t *house_constructor(scenes_t *scene, window_t *window_data);
scenes_t *loading_constructor(scenes_t *scene, window_t *window_data);
object_t **create_loading_obj(scenes_t *scene, window_t *window_data);
scenes_t *world_constructor(scenes_t *scene, window_t *window_data);
scenes_t *dungeon_constructor(scenes_t *scene, window_t *window_data);

sfSprite **sprites_copy(sfSprite **sprite);
// fight constructor
scenes_t *fight_constructor(scenes_t *scene, window_t *window_data);
sfText **create_scene_text(window_t *window_data);
void create_player_text(sfText **text, sfFont *font);
void create_enemy_text(sfText **text, enemy_t *enemy, sfFont *font);
buttons_t **create_fight_scene_buttons(scenes_t *scene, window_t *window_data);
buttons_t *create_fight_button(buttons_t *button, window_t *window_data,
                                                char *string, sfVector2f pos);
buttons_t **allocate_buttons(int button_count);
sfText **create_special_text(window_t *window_data);
// game obj dungeon
game_objects_t *dungeon_game_object(scenes_t *scene, window_t *window_data);
void set_center_sprite(sfSprite **sprite);
enemy_t *create_enemy(enemy_t *enemy, window_t *window_data, char *name,
                                                                    int type);
sfSprite **copy_sprite(char *name, window_t *window_data);
void set_sprite(sfSprite **sprite, sfVector2f pos);
enemy_t **allocate_dungeon_enemies(scenes_t *scene);

// fight mode
void heal(void *scene_ptr, window_t *window_data);
void special_attack(void *scene_ptr, window_t *window_data);
void normal_attack(void *scene_ptr, window_t *window_data);
void enemy_turn(scenes_t *scene, window_t *window_data);

// create enemies in scene fight
enemy_t **create_all_enemies(enemy_t **enemies, window_t *window_data);
int create_all_easy_enemies(enemy_t **enemies, window_t *window_data,
                                                            int enemy_count);
int create_all_medium_enemies(enemy_t **enemies, window_t *window_data,
                                                            int enemy_count);
int create_all_boss(enemy_t **enemies, window_t *window_data);
char *set_enemy_name(char *asset_name);
void move(scenes_t *scene, sfView *view, float y_offset, float x_offset);
void move_keys(scenes_t *scene, char **grid, short *i);

// drawers
void loading_drawer(scenes_t *scene, window_t *window_data);
void world_drawer(scenes_t *scene, window_t *window_data);
void character_drawer(scenes_t *scene, window_t *window_data);
void fight_drawer(scenes_t *scene, window_t *window_data);

enemy_t **allocate_enemies(void);
scenes_t *character_constructor(scenes_t *scene, window_t *window_data);
buttons_t *set_button(char **tab, window_t *window_data, sfColor *color,
                                                            sfFloatRect rect);
// input managers

void check_npc_world_event(scenes_t *scene, window_t *, char **, int);
void check_npc_dungeon_event(scenes_t *scene, window_t *, char **);
void world_input(scenes_t *scene, window_t *window_data);
void loading_input(scenes_t *scene, window_t *window_data);
void character_input(scenes_t *scene, window_t *window_data);
void fight_input(scenes_t *scene, window_t *window_data);
void check_other_trigger(scenes_t *scene, char **grid);

void input_rectangle_button(sfRenderWindow *window, sfEvent event,
                                                            buttons_t *button);
buttons_t *set_input(char *str, window_t *window_data, sfColor color,
                                                            sfFloatRect rect);
void input_enter(sfEvent event, buttons_t *input, buttons_t *next_input);
void input_alphabetical(sfEvent event, buttons_t *input);
void input_number(sfEvent event, buttons_t *input);
void input_delete(sfEvent event, buttons_t *input);
void enemy_trigger(scenes_t *scene, window_t *window_data, char **grid);

/*
** src/scenes/utils
*/

sfFloatRect get_window_rect(sfRenderWindow *window, sfFloatRect rect);
sfRectangleShape *create_button_rectangleshape(sfColor color, sfFloatRect);
sfText *create_button_text(char *str, sfFont *, sfColor, sfFloatRect rect);
int play_music(scenes_t*scene, int check);
int check_elapsed_time(sfClock *clock, float check, float time_to_wait);
void display_hud(player_t *player, window_t *window_data);
void display_hud_enemy(window_t *window_data, int hp, char *name,
                                                            sfVector2f pos);
int scale_player(loaded_sprites_t **player, int check, sfVector2f scale);
int scale_animated_player(animated_sprites_t *player, int check,
                                                            sfVector2f scale);
char *str_fusion(char *str1, char *str2);
void create_hud(window_t *window_data, player_t *player, int type, int gender);
// allocate obj
object_t **allocate_obj(int obj_count);

sfText *create_text(sfFont *font, char *string, sfColor color, int size);
sfText *move_text(sfText *text, int x, int y);
sfSprite **get_sprite_asset(char *name, loaded_sprites_t **category);
sfSprite *get_background_asset(char *name, loaded_sprites_t **background);
void display_animated_sprite(window_t *window_data,
                        animated_sprites_t *animated_sprites, int animation);
void change_sprite_count(window_t *window_data,
                        animated_sprites_t *animated_sprites, int animation);
void place_scale_sprite_sheet(sfSprite **sprites, sfVector2f pos,
                                                            sfVector2f scale);

// create scenes
game_t *create_scenes(game_t *game_data);
hud_player_t *set_hud(void);
game_t *call_constructors(game_t *game_data);

// create player attacks
attack_t *init_attack_heal(void);
attack_t *init_attack_spe(void);
attack_t *init_attack_normal(void);
// create player
player_t *set_player(void);
player_t *set_player_sprites(player_t *player);
player_t *set_player_attacks(player_t *player);
// create enemy
enemy_t *create_boss_enemy(enemy_t *enemy, sfSprite **sprite, char *name);
enemy_t *create_medium_enemy(enemy_t *enemy, sfSprite **sprite, char *name);
enemy_t *create_easy_enemy(enemy_t *enemy, sfSprite **sprite, char *name);
attack_t *create_attack(char *name, int damage);


// set func ptr
void set_function_pointers(game_t *game_data);
void set_input_managers(game_t *game_data);
void set_drawers(game_t *game_data);
void set_constructors(game_t *game_data);

// display basics
void display_special_text(scenes_t *scene, window_t *window_data);
void display_text(scenes_t *scene, window_t *window_data);
void display_background(scenes_t *scene, window_t *window_data);
void display_buttons(buttons_t **buttons, window_t *window_data);
void display_fight_buttons(buttons_t **buttons, window_t *window_data);

#endif /* !PROTOTYPE_H_ */
