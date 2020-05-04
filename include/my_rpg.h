/*
** EPITECH PROJECT, 2020
** include file
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

// boolean macros
#define TRUE 0
#define FALSE 1

// window size macros
#define HEIGHT 1080
#define WIDTH 1920

// return values macros
#define SUCCESS 0
#define ERR 84

// scene number macro
#define SCENE_NUMBER 6

// buttons macros
#define RECTANGLE 1
#define SPRITE 2
#define SLIDER 3
#define INPUT 4

// music macros
#define MUSIC_1 0
#define MUSIC_2 1

// sprite sheet creation informations
#define ENTITY_SPRITE_COUNT 16
#define PLAYER_SPRITE_COUNT 10

// assets array values
#define MUSIC_COUNT 4
#define FONT_COUNT 3


///// WORLD MACROS /////
// world pos macros
#define PLAYER_HOUSE {.x = 25, .y = 16}

#define DUNGEON_X 45
#define DUNGEON_Y 99



// CODE ERGONOMY MACROS

#define MOVE_VEC (sfVector2f){.x = 24 * x_offset, .y = 24 * y_offset}

//pointers macros
#define GRID pointers[0]
// c'est 3 pcq ya le cube en attendant les sprites
#define WORLD_PTR_MAX pointers[1]

// scenes index in scene array
enum scenes {
    LOADING_SCENE,
    WORLD,
    CHARACTER_SCENE,
    HOUSE,
    DUNGEON,
    FIGHT,
    END,
};

// fonts index values in window_data->fonts[]
enum fonts {
    RALEWAY,
    POPPINS,
    CORONOS,
};

// music index vlues in window_data->musics[]
enum musics {
    ARRIVAL,
    NOCTURIAL,
    CELESTIAL,
    RED_CARPET,
};

enum animation {
    RUN,
    IDLE,
    HIT,
};

enum ememy_type {
    BOSS,
    MEDIUM,
    EASY,
};

enum enemy_status {
    DEAD,
    ALIVE,
};

#define ENEMY_COUNT 14

#endif /* !MY_RPG_H_ */
