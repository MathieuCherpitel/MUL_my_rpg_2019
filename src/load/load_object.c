/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_any_sprites
*/

#include <stdlib.h>
#include "libmy.h"
#include "prototype.h"

static loaded_sprites_t *load_sprite(char *filepath,
                                    loaded_sprites_t *sprite, int scale)
{
    sfIntRect rect = {0, 0, 13, 30};

    my_putstr("loading : ");
    my_putstr(filepath);
    my_putchar('\n');
    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    for (int i = 0; i < 8; i++) {
        sprite->sprite[i] = sfSprite_create();
        if (sprite->sprite[i] == NULL)
            return (NULL);
        sfSprite_setTexture(sprite->sprite[i], sprite->texture, sfTrue);
        sfSprite_setTextureRect(sprite->sprite[i], rect);
        sfSprite_scale(sprite->sprite[i], (sfVector2f)
                                                {.x = scale, .y = scale});
        rect.left += 13;
    }
    sprite->sprite[8] = NULL;
    sprite->name = get_asset_name(filepath);
    return (sprite);
}

loaded_sprites_t **load_object(char **assets_path,
                                                loaded_sprites_t **sprites)
{
    int scale = 3.5;
    int tab_len = get_tab_len(assets_path);
    int count = 0;

    sprites = malloc(sizeof(loaded_sprites_t *) * (tab_len + 1));
    while (count < tab_len) {
        sprites[count] = malloc(sizeof(loaded_sprites_t));
        if (sprites[count] == NULL)
            return (NULL);
        sprites[count]->sprite = malloc(sizeof(sfSprite *) * (9));
        if (sprites[count]->sprite == NULL)
            return (NULL);
        sprites[count] = load_sprite(assets_path[count],
                                                    sprites[count], scale);
        count++;
    }
    sprites[count] = NULL;
    my_putchar('\n');
    return (sprites);
}
