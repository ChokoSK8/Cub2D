/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:02:19 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 14:21:58 by abrun            ###   ########.fr       */
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

void	move_key_back(t_player *hero, t_img img)
{
	t_vect	h;

	h.y = hero->vec.y + hero->speed
		* cos(convert(hero->angle));
	h.x = hero->vec.x + hero->speed
		* sin(convert(hero->angle));
	if (!is_wall_around(h, img))
	{
		hero->vec.y += hero->speed
			* cos(convert(hero->angle));
		hero->vec.x += hero->speed
			* sin(convert(hero->angle));
	}
}

int	display(t_param *param)
{
	if (param->move.s)
		move_key_back(&param->hero, param->img_map);
	if (param->move.w)
		move_key_forward(&param->hero, param->img_map);
	if (param->move.a)
		move_key_left(&param->hero, param->img_map);
	if (param->move.d)
		move_key_right(&param->hero, param->img_map);
	if (param->move.r)
		param->hero.angle -= 1;
	if (param->move.l)
		param->hero.angle += 1;
	param->hero.angle = get_angle_right(param->hero.angle, 0);
	display_multi_angle(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.image, 0, 0);
	return (1);
}
