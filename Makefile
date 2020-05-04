##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/main_functions/main.c						\
		src/main_functions/rpg.c						\
		src/event/check_event.c							\
		src/load/get_assets.c 							\
		src/load/load_any_sprites.c 						\
		src/load/load_object.c 						\
		src/load/load_npc.c 						\
		src/load/load_ui.c 						\
		src/load/load_assets.c 							\
		src/load/load_entities.c 						\
		src/load/load_players.c 						\
		src/load/load_sprites_players.c							\
		src/load/load_sprites.c							\
		src/main_functions/game_loop.c					\
		src/main_functions/check_win.c 				\
		src/scenes/create_scenes/set_func_ptrs.c		\
		src/scenes/create_scenes/create_scenes.c				\
		src/scenes/create_scenes/create_player.c 					\
		src/scenes/create_scenes/create_player_attacks.c			\
		src/scenes/create_scenes/create_enemy.c 				\
		src/scenes/constructors/world_constructor.c				\
		src/scenes/constructors/loading_constructor.c				\
		src/scenes/constructors/loading_obj_constructor.c			\
		src/scenes/constructors/character_constructor.c				\
		src/scenes/constructors/create_all_enemies.c 		\
		src/scenes/constructors/fight_constructor.c			\
		src/scenes/constructors/fight_text.c				\
		src/scenes/constructors/create_fight_button.c		\
		src/scenes/constructors/fight_mode.c				\
		src/scenes/constructors/dungeon_game_obj.c 			\
		src/scenes/constructors/create_enemy_dungeon_scene.c 	\
		src/scenes/constructors/places_constructors.c 		\
		src/scenes/drawers/loading_drawer.c 					\
		src/scenes/drawers/character_drawer.c 					\
		src/scenes/drawers/world_drawer.c 					\
		src/scenes/drawers/fight_drawer.c 					\
		src/scenes/input_managers/loading_input.c				\
		src/scenes/input_managers/character_input.c				\
		src/scenes/input_managers/world_input.c				\
		src/scenes/input_managers/fight_input.c 				\
		src/scenes/input_managers/enemies_trigger.c 		\
		src/scenes/input_managers/event_triggers.c 			\
		src/scenes/input_managers/movement_input.c          \
		src/scenes/utils/allocate_obj.c 				\
		src/scenes/utils/input_rectangle_button.c				\
		src/scenes/utils/input_input_button.c				\
		src/scenes/utils/set_button.c				\
		src/scenes/utils/set_rectangle_button.c				\
		src/scenes/utils/set_input_button.c				\
		src/scenes/utils/create_text.c						\
		src/scenes/utils/create_hud.c						\
		src/scenes/utils/display_hud.c						\
		src/scenes/utils/display_basics.c					\
		src/scenes/utils/display_animated_sprite.c					\
		src/scenes/utils/get_asset.c						\
		src/scenes/utils/str_fusion.c					\
		src/scenes/utils/display_hud_enemy.c						\
		src/scenes/utils/scale_player.c						\
		src/scenes/utils/check_time_elapsed.c						\
		src/scenes/utils/play_music.c						\
		src/scenes/utils/check_npc_event.c						\
		src/scenes/utils/place_scale_sprites.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CGRAPHFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-audio -lcsfml-system -g -lm

CFLAGS =	-Wall -Wextra -W -g -I./include

all:	$(NAME) $(TEST)

$(NAME):	$(OBJ)
	@make -s -C lib/my
	gcc -o $(NAME) $(CFLAGS) $(CGRAPHFLAGS) $(OBJ) -L./lib/my -lmy

test:
	make
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	@make -s -C lib/my fclean
	$(RM) $(NAME)

re:	fclean all
	@make -s -C lib/my re

.PHONY:	clean
