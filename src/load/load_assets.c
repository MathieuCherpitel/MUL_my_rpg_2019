/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_assets
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "libmy.h"
#include "prototype.h"

window_t *load_music(window_t *window_data)
{
    char dir[] = "rpg_assets/musics/";
    char *name[] = {"The_arrival__BATTLE-II_.ogg", "Nocturnal_mysteries.ogg",
    "Celestial.ogg", "Red_carpet_wooden_floor.ogg", NULL};

    window_data->musics = malloc(sizeof(sfMusic *) * (MUSIC_COUNT + 1));
    if (window_data->musics == NULL)
        return (NULL);
    for (int i = 0; i < MUSIC_COUNT; i++) {
        window_data->musics[i] = sfMusic_createFromFile(str_fusion(dir, name[i]));
        sfMusic_setLoop(window_data->musics[i], sfTrue);
        sfMusic_pause(window_data->musics[i]);
        sfMusic_setVolume(window_data->musics[i], 42);
    }
    sfMusic_setVolume(window_data->musics[NOCTURIAL], 14);
    return (window_data);
}

window_t *load_fonts(window_t *window_data)
{
    window_data->fonts = malloc(sizeof(sfFont *) * (FONT_COUNT + 1));
    if (window_data->fonts == NULL)
        return (NULL);
    window_data->fonts[RALEWAY] = sfFont_createFromFile
                                ("rpg_assets/fonts/Raleway-Regular.ttf");
    window_data->fonts[POPPINS] = sfFont_createFromFile
                            ("rpg_assets/fonts/Poppins-BlackItalic.ttf");
    window_data->fonts[CORONOS] = sfFont_createFromFile
                                ("rpg_assets/fonts/song_of_conoros.ttf");
    return (window_data);
}

window_t *load(window_t *window_data)
{
    my_putstr("loading images\n");
    window_data = load_sprites(window_data);
    if (window_data == NULL)
        return (NULL);
    my_putstr("\nloading music\n");
    window_data = load_music(window_data);
    if (window_data == NULL)
        return (NULL);
    my_putstr("loading fonts\n");
    window_data = load_fonts(window_data);
    if (window_data == NULL)
        return (NULL);
    my_putstr("\nloading done\n");
    return (window_data);
}

window_t *load_assets(game_t *game_data)
{
    game_data->window_data = load(game_data->window_data);
    if (game_data->window_data == NULL)
        return (NULL);
    return (game_data->window_data);
}