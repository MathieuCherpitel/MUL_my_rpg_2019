/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_any_sprites
*/

#include <stdlib.h>
#include "libmy.h"
#include "prototype.h"

static loaded_sprites_t *load_sprite(char *filepath, loaded_sprites_t *sprite)
{
    my_putstr("loading : ");
    my_putstr(filepath);
    my_putchar('\n');
    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite[0] = sfSprite_create();
    if (sprite->sprite[0] == NULL)
        return (NULL);
    sprite->sprite[1] = NULL;
    sprite->name = get_asset_name(filepath);
    sfSprite_setTexture(sprite->sprite[0], sprite->texture, sfTrue);
    return (sprite);
}

loaded_sprites_t **load_any_sprites(char **assets_path,
                                                loaded_sprites_t **sprites)
{
    int tab_len = get_tab_len(assets_path);
    int count = 0;

    sprites = malloc(sizeof(loaded_sprites_t *) * (tab_len));
    while (count < tab_len) {
        sprites[count] = malloc(sizeof(loaded_sprites_t));
        if (sprites[count] == NULL)
            return (NULL);
        sprites[count]->sprite = malloc(sizeof(sfSprite *) * (2));
        if (sprites[count]->sprite == NULL)
            return (NULL);
        sprites[count] = load_sprite(assets_path[count], sprites[count]);
        count++;
    }
    my_putchar('\n');
    return (sprites);
}
