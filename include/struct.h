/*
** EPITECH PROJECT, 2020
** include struct file
** File description:
** my_rpg
*/

#ifndef STRUCT_H
#define STRUCT_H

// csfml includes
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>


typedef struct animated_sprites_s {
    sfSprite **sprites;
    int sprite_count;
    int even;
    int odd;
}animated_sprites_t;

typedef struct loaded_sprites_s {
    char *name;
    sfTexture *texture;
    sfSprite **sprite;
}loaded_sprites_t;

typedef struct loaded_assets_s {
    loaded_sprites_t **enemy;
    loaded_sprites_t **npc;
    loaded_sprites_t **objects;
    loaded_sprites_t **weapons;
    loaded_sprites_t **player;
    loaded_sprites_t **UI;
    loaded_sprites_t **background;
}loaded_assets_t;

typedef struct attack_s {
    char *name;
    int damage;
    int effect;
}attack_t;

typedef struct weapon_s {
    char *name;
    sfSprite *sprite;
    float hp_multiplier;
    float damage_multiplier;
    float speed_multiplier;
    int active;
}weapon_t;

typedef struct inventory_object_s {
    char *name;
    sfSprite *sprite;
}inventory_object_t;

typedef struct inventory_s {
    weapon_t **weapon;
    inventory_object_t **object;
}inventory_t;

typedef struct hud_player_s {
    sfText *name;
    sfText *hp_text;
    sfText *speed_text;
    sfText *att1_text;
    sfText *att2_text;
    sfText *mana_text;
    sfSprite **hud_sprites;
    sfSprite **bar_sprites;
    sfSprite **objects_sprites;
    sfVector2f hp_pos;
    sfVector2f mana_pos;
    int *active;
}hud_player_t;

typedef struct player_s {
    char *name;
    int hp;
    int xp;
    int mana;
    int speed;
    int heal;
    int normal_attack;
    int special_attack;
    int quest_obj_1;
    sfIntRect *hitbox;
    sfSound **sounds; 
    attack_t **attacks;
    inventory_t *inventory;
    animated_sprites_t *animated_sprite;
    hud_player_t *hud;
    int turn;
}player_t;


typedef struct enemy_s {
    char *name;
    int hp;
    sfIntRect *hitbox;
    sfText **dialog;
    sfSound **sound;
    attack_t **attacks;
    animated_sprites_t *animated_sprite;
    sfVector2i pos;
    int status;
}enemy_t;


typedef struct npc_s {
    char *name;
    int active;
    int current_dialog;
    sfSprite **dialog;
    sfIntRect *hitbox;
    sfSound **sound;
    animated_sprites_t *animated_sprite;
}npc_t;

typedef struct window_s {
    sfRenderWindow *render_window;
    sfEvent event;
    sfView *view;
    sfClock *clock;
    sfClock *anim;
    loaded_assets_t *loaded_assets;
    sfMusic **musics;
    sfFont **fonts;
    int current_size;
    sfVector2u *screen_size;
    int current_scene;
    enemy_t **enemies;
    enemy_t *current_enemy;
    void *dungeon_ptr;
    void *ptr;
}window_t;

typedef struct slider_s {
    sfSprite *slider_bar;
    sfSprite *slider_button;
    sfVector2f *left_position;
    sfVector2f right_position;
}slider_t;

typedef struct buttons_s {
    sfRectangleShape *rect;
    void (*callback)(void *, window_t *);
    sfSprite **sprites;
    sfSprite *sprite_to_draw;
    slider_t *slider;
    int button_type;
    int selected;
    int current_color;
    int current_text;
    int index;
    char *str;
    sfText **text;
    sfColor *color;
    sfFloatRect hitbox;
}buttons_t;

typedef struct object_s {
    animated_sprites_t *animated_sprite;
    sfTexture *texture;
    sfIntRect *hitbox;
    void (*object_interaction)(window_t *);
}object_t;

typedef struct game_objects_s {
    object_t **objects;
    sfSound **sounds;
    enemy_t **enemies;
    npc_t **npc;
}game_objects_t;

typedef struct scenes_s {
    game_objects_t *game_objects;
    buttons_t **buttons;
    sfSprite *background;
    sfText **text;
    sfText **special_text;
    sfMusic *music;
    player_t *player;
    void **pointers;
    void (*input_method)(struct scenes_s *, window_t *window_data);
    void (*drawer)(struct scenes_s *, window_t *window_data);
    struct scenes_s *(*constructor)(struct scenes_s *, window_t *window_data);
    sfView *view;
    sfVector2f pos;
    enemy_t *current_enemy;
    int music_start;
    animated_sprites_t *player_copy;
}scenes_t;


typedef struct game_s {
    window_t *window_data;
    scenes_t **scenes;
    sfVector2f **size;
    int win;
}game_t;


#endif /* !STRUCT_H */
