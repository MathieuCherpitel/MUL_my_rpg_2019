/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_assets
*/

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "libmy.h"
#include "prototype.h"
#include "my_rpg.h"

int get_file_count(char *folder_name)
{
    DIR *dir = opendir(folder_name);
    int count = 0;
    struct dirent *dire_info;

    my_putstr("loading directory : ");
    my_putstr(folder_name);
    my_putchar('\n');
    while ((dire_info = readdir(dir)) != NULL) {
        if (dire_info->d_type != DT_REG
                && my_strcmp(dire_info->d_name, ".") != 0
                && my_strcmp(dire_info->d_name, "..") != 0) {
            return (-1);
        }
        if (my_strcmp(dire_info->d_name, ".") != 0
                                && my_strcmp(dire_info->d_name, "..") != 0)
            count++;
    }
    closedir(dir);
    return (count);
}

char *get_asset_path(char *folder_path, char *file_path)
{
    char *dest = malloc(sizeof(char) * (my_strlen
                                (folder_path) + my_strlen(file_path) + 1));

    if (dest == NULL)
        return (NULL);
    dest = my_strcpy(dest, folder_path);
    dest = my_strcat(dest, file_path);
    return (dest);
}

char **get_assets_names(char **assets_names, char *folder_name)
{
    int count = 0;
    struct dirent *dire_info;
    char *tmp = malloc(sizeof(char) * (my_strlen(folder_name) + 2));
    DIR *dir = opendir(folder_name);

    tmp = my_strcpy(tmp, folder_name);
    tmp = my_strcat(tmp, "/");
    while ((dire_info = readdir(dir)) != NULL) {
        if (dire_info == NULL)
            return (NULL);
        if (dire_info->d_type == DT_REG) {
            assets_names[count] = get_asset_path(tmp, dire_info->d_name);
            count++;
        }
    }
    assets_names[count] = NULL;
    closedir(dir);
    return (assets_names);
}

char **get_assets(char *folder_name)
{
    int file_count = get_file_count(folder_name);
    char **assets_names;

    if (file_count == -1)
        return (NULL);
    assets_names = malloc(sizeof(char *) * (file_count + 1));
    if (assets_names == NULL)
        return (NULL);
    assets_names = get_assets_names(assets_names, folder_name);
    if (assets_names == NULL)
        return (NULL);
    return (assets_names);
}