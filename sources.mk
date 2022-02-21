## SOURCES.MK ##

## SRCS ##

SOURCES		+=                                        		\
		Srcs/main.c                                      	\


## SRCS/FREE_PARAM ##

SOURCES		+=                                        		\
		Srcs/Free_param/destroy_win.c                    	\
		Srcs/Free_param/free_param_2.c                   	\
		Srcs/Free_param/free_param.c                     	\


## SRCS/DISPLAY ##

SOURCES		+=                                        		\
		Srcs/Display/dis_map.c                           	\
		Srcs/Display/dis_hero.c                          	\
		Srcs/Display/dis_background.c                    	\


## SRCS/DISPLAY/DIS_WALLS ##

SOURCES		+=                                        		\
		Srcs/Display/Dis_walls/dis_walls.c               	\
		Srcs/Display/Dis_walls/get_texture.c             	\
		Srcs/Display/Dis_walls/dis_walls_utils.c         	\


## SRCS/GET_DISTANCES ##

SOURCES		+=                                        		\
		Srcs/Get_distances/get_dist_hori.c               	\
		Srcs/Get_distances/get_dist_vert.c               	\
		Srcs/Get_distances/get_dist_vert_utils.c         	\
		Srcs/Get_distances/get_dist_utils.c              	\


## SRCS/TOOLS ##

SOURCES		+=                                        		\
		Srcs/Tools/get_next_line.c                       	\
		Srcs/Tools/error_malloc.c                        	\
		Srcs/Tools/ft_putstr_str.c                       	\


## SRCS/INITIALISATION ##

SOURCES		+=                                        		\
		Srcs/Initialisation/init_param.c                 	\
		Srcs/Initialisation/init_hero_utils.c            	\
		Srcs/Initialisation/error_init_param.c           	\
		Srcs/Initialisation/init_param_utils.c           	\


## SRCS/INITIALISATION/INIT_WALLS ##

SOURCES		+=                                        		\
		Srcs/Initialisation/Init_walls/init_walls.c      	\


## SRCS/GAMEPLAY ##

SOURCES		+=                                        		\
		Srcs/Gameplay/move_hero_utils.c                  	\
		Srcs/Gameplay/move_hero.c                        	\


## SRCS/CHECKS ##

SOURCES		+=                                        		\
		Srcs/Checks/check_file.c                         	\


## SRCS/CHECKS/CHECK_MAP ##

SOURCES		+=                                        		\
		Srcs/Checks/Check_map/check_map.c                	\
		Srcs/Checks/Check_map/is_surrounded.c            	\
		Srcs/Checks/Check_map/is_space_in_map.c          	\


## SRCS/CHECKS/CHECK_ELEMENTS ##

SOURCES		+=                                        		\
		Srcs/Checks/Check_elements/check_all.c           	\
		Srcs/Checks/Check_elements/check_elements.c      	\


## SRCS/GET_PARAM_CUB ##

SOURCES		+=                                        		\
		Srcs/Get_param_cub/get_map.c                     	\
		Srcs/Get_param_cub/get_textures.c                	\
		Srcs/Get_param_cub/get_map_utils.c               	\
		Srcs/Get_param_cub/exit_get_param.c              	\
		Srcs/Get_param_cub/get_color.c                   	\
		Srcs/Get_param_cub/get_param_cub.c               	\


