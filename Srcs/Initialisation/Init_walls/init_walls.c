/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:38:09 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 13:37:16 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void	init_walls(t_param *param)
{
	param->walls.wall1.img.image = 0;
	param->walls.wall2.img.image = 0;
	param->walls.wall3.img.image = 0;
	param->walls.wall4.img.image = 0;
	init_wall1_img(&param->walls.wall1, *param);
	init_wall2_img(&param->walls.wall2, *param);
	init_wall3_img(&param->walls.wall3, *param);
	init_wall4_img(&param->walls.wall4, *param);
}

void	init_wall4_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.ea,
			&wall->img.width, &wall->img.height);
	if (!wall->img.image)
		error_file_wall(&param, param.ea);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}

void	init_wall3_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.we,
			&wall->img.width, &wall->img.height);
	if (!wall->img.image)
		error_file_wall(&param, param.we);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}

void	init_wall2_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.so,
			&wall->img.width, &wall->img.height);
	if (!wall->img.image)
		error_file_wall(&param, param.so);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}

void	init_wall1_img(t_wall *wall, t_param param)
{
	wall->img.image = mlx_xpm_file_to_image(param.mlx, param.no,
			&wall->img.width, &wall->img.height);
	if (!wall->img.image)
		error_file_wall(&param, param.no);
	wall->img.data = mlx_get_data_addr(wall->img.image, &wall->img.bpp,
			&wall->img.size_line, &wall->img.endian);
}
