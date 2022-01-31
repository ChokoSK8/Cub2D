/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:02:19 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 13:20:44 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	is_wall_around(t_vect hero, t_img img)
{
	int		x;
	int		y;
	int		x_final;
	int		y_final;
	int		pos;

	y = (int)hero.y - 2;
	x_final = (int)hero.x + 2;
	y_final = (int)hero.y + 2;
	while (y < y_final)
	{
		x = (int)hero.x - 2;
		while (x < x_final)
		{
			pos = x * 4 + img.size_line * y;
			if (img.data[pos])
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	display(t_param *param)
{
	display_multi_angle(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.image, 0, 0);
	return (1);
}
