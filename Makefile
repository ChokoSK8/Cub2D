# Colors
C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m

NAME		= cub3D

LIB_MLX		= Minilibx-linux/libmlx.a Minilibx-linux/libmlx_Linux.a

LIB		= Libft/libft.a

SRCS		= Free_param/free_param.c Free_param/destroy_win.c Free_param/free_param_2.c\
	Checks/Check_elements/check_all.c Checks/Check_elements/check_elements.c \
	Checks/Check_map/check_map.c Checks/Check_map/is_surrounded.c Checks/Check_map/is_space_in_map.c \
	Checks/check_file.c \
	Display/dis_background.c Display/dis_hero.c Display/dis_map.c \
	Display/Dis_walls/dis_walls.c Display/Dis_walls/dis_walls_utils.c Display/Dis_walls/get_texture.c \
	Gameplay/move_hero.c Gameplay/move_hero_utils.c \
	Get_distances/get_dist_hori.c Get_distances/get_dist_utils.c Get_distances/get_dist_vert.c Get_distances/get_dist_vert_utils.c \
	Get_param_cub/get_color.c Get_param_cub/get_map.c Get_param_cub/get_map_utils.c Get_param_cub/get_param_cub.c Get_param_cub/get_textures.c Get_param_cub/exit_get_param.c \
	Initialisation/init_hero_utils.c Initialisation/init_param.c Initialisation/init_param_utils.c \
	Initialisation/Init_walls/init_walls.c Initialisation/Init_walls/error_file_wall.c \
	Tools/get_next_line.c Tools/ft_putstr_str.c Tools/error_malloc.c \
	main.c

MLX_SRCS	= Mlx_fcts/mlx_shaders.c Mlx_fcts/mlx_new_window.m Mlx_fcts/mlx_init_loop.m Mlx_fcts/mlx_new_image.m Mlx_fcts/mlx_xpm.c Mlx_fcts/mlx_int_str_to_wordtab.c

PATH_SRCS	= Srcs/

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS		= $(_SRCS:.c=.o)

MLX_OBJS	= $(MLX_SRCS:.c=.o)

MLX_OBJS_M	= $(MLX_OBJS:.m=.o)

RM			= rm -rf

INC			= -I/usr/include -Imlx_linux

FLAGS			= -Wall -Wextra -Werror #-g3 -fsanitize=address

MLX_FLAGS		= -lm -lX11 -lXext

%.o: %.c
		@gcc -g $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(NAME):	$(OBJS)
	@make -C Libft
	@echo "[$(C_CYAN)COMPILING Minilibx$(C_END)]"
	@make -C Minilibx-linux
	@echo "[$(C_YELLOW)CREATING Cub3D$(C_END)]"
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIB_MLX) $(MLX_FLAGS)
	@echo "[$(C_PURPLE)Cub3D ready to be used$(C_END)]"

clean:
	@echo "[$(C_BLUE)CLEANING objects$(C_END)]"
	@$(RM) $(OBJS)
	@echo "[$(C_RED)CLEANING Libft$(C_END)]"
	@make clean -C Libft
	@echo "[$(C_WHITE)CLEANING Minilibx$(C_END)]"
	@make clean -C Minilibx-linux

fclean:		clean
	@$(RM) $(NAME)
	@make fclean -C Libft

re:		fclean all

.PHONY:		all clean fclean re
