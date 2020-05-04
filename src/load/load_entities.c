/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_enemies
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"
#include "prototype.h"

sfIntRect get_entity_rect(char *name)
{
    char *boss[] = {"big_demon.png", "big_zombie.png", "ogre.png", NULL};
    char *medium[] = {"ice_zombie.png", "masked_orc.png", "necromancer.png",
                                "orc_shaman.png", "orc_warrior.png", NULL};
    sfIntRect rect_boss = {.left = 0, .top = 0, .width = 32, .height = 36};
    sfIntRect rect_medium = {.left = 0, .top = 0, .width = 16, .height = 20};
    sfIntRect rect_easy = {.left = 0, .top = 0, .width = 16, .height = 16};

    for (int i = 0; boss[i] != NULL; i++) {
        if (my_strcmp(boss[i], name) == 0) {
            return (rect_boss);
        }
    }
    for (int i = 0; medium[i] != NULL; i++) {
        if (my_strcmp(medium[i], name) == 0) {
            return (rect_medium);
        }
    }
    return (rect_easy);
}

sfSprite **load_entity_sprite_sheet(sfTexture *texture, char *name)
{
    int index = 0;
    sfIntRect rect = get_entity_rect(name);
    sfSprite **sprite = malloc(sizeof(sfSprite *) * 9);
    int left = rect.width;
    int top = rect.height;

    for (int i = 0; i < 2; i++) {
        for (int c = 0; c < 4; c++) {
            sprite[index] = sfSprite_create();
            sfSprite_setTexture(sprite[index], texture, sfTrue);
            sfSprite_setTextureRect(sprite[index], rect);
            rect.left += left;
            index++;
        }
        rect.top += top;
    }
    sprite[index] = NULL;
    return (sprite);
}

loaded_sprites_t **load_entities_loop(char **assets_path,
                                        loaded_sprites_t **entities)
{
    int count = 0;

    while (assets_path[count] != NULL) {
        entities[count] = malloc(sizeof(loaded_sprites_t));
        if (entities[count] == NULL)
            return (NULL);
        entities[count]->sprite = malloc(sizeof(sfSprite *) * 
                                                (ENTITY_SPRITE_COUNT));
        if (entities[count] == NULL || entities[count]->sprite == NULL)
            return (NULL);  
        entities[count]->name = get_asset_name(assets_path[count]);
        entities[count]->texture = sfTexture_createFromFile
                                                (assets_path[count], NULL);
        entities[count]->sprite = load_entity_sprite_sheet
                        (entities[count]->texture, entities[count]->name);
        count++;
    }
    entities[count] = NULL;
    return (entities);
}

loaded_sprites_t **load_entities(char **assets_path,
                                            loaded_sprites_t **entities)
{
    int assets_count = get_tab_len(assets_path);

    entities = malloc(sizeof(loaded_sprites_t *) *(assets_count + 1));
    if (entities == NULL)
        return (NULL);
    entities = load_entities_loop(assets_path, entities);
    if (entities == NULL)
        return (NULL);
    return (entities);
}
