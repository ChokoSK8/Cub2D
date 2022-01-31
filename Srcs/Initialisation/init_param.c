/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:36:29 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 14:49:48 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	init_param(t_param *param)
{
	param->mlx = mlx_init();
	mlx_get_screen_size(param->mlx, &param->max_w, &param->max_h);
	param->width = param->max_w * 0.9;
	param->height = param->max_h * 0.9;
	init_checks(param);
	if (!get_param_cub(param))
		return (0);
	if (!(init_map(&param->map, param->tab, param)))
		return (0);
	init_wall1_img(&param->walls.wall1, *param);
	init_wall2_img(&param->walls.wall2, *param);
	init_wall3_img(&param->walls.wall3, *param);
	init_wall4_img(&param->walls.wall4, *param);
	param->d_max = get_dist_max(param->map);
	init_img(&param->img, *param);
	param->win = mlx_new_window(param->mlx, param->width,
			param->height, "Cub3D");
	init_hero(&param->hero, param->map);
	return (1);
}

void	init_img(t_img *img, t_param param)
{
	int		bpp;
	int		size_line;
	int		endian;
	void	*image;
	char	*img_data;

	image = mlx_new_image(param.mlx, param.width, param.height);
	img_data = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	img->bpp = bpp;
	img->endian = endian;
	img->size_line = size_line;
	img->data = img_data;
	img->image = image;
}

int	init_map(t_map *map, char *tab, t_param *param)
{
	map->map = get_map(tab, param);
	if (!map->map)
		return (0);
	map->height = get_height(tab);
	map->max_width = get_max_width(tab);
	free(tab);
	if (!is_pos_hero(map->map)
		|| !is_surrounded(map->height, map->max_width, map->map)
		|| !is_characters_ok(map->map)
		|| is_space_in_map(map->map, map->height, map->max_width))
	{
		free_map_param(param);
		return (0);
	}
	map->dir = get_dir(*map);
	map->len_pix = 64;
	return (1);
}

void	init_hero(t_player *hero, t_map map)
{
	t_point	pt_h;

	pt_h = get_pos_hero(map);
	hero->angle = get_angle(map);
	hero->vec.x = (pt_h.x + 1) * map.len_pix - map.len_pix / 2;
	hero->vec.y = (pt_h.y + 1) * map.len_pix - map.len_pix / 2;
	hero->len = 2;
	hero->speed = 3;
}

void	init_checks(t_param *param)
{
	int	counter;

	counter = 0;
	while (counter < 6)
	{
		param->checks[counter] = 0;
		counter++;
	}
}
