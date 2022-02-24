/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:02:19 by abrun             #+#    #+#             */
/*   Updated: 2022/02/24 15:30:12 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	is_wall_around(t_player hero, t_img img, t_vect end)
{
	t_point	pt;
	t_point	fin;
	int		pos;
	int		c;

	c = 105;
	while (c--)
	{
		hero.vec.y += (end.y / 100);
		hero.vec.x += (end.x / 100);
		pt.y = (int)hero.vec.y - 5;
		fin.x = (int)hero.vec.x + 4;
		fin.y = (int)hero.vec.y + 4;
		while (++pt.y < fin.y)
		{
			pt.x = (int)hero.vec.x - 5;
			while (++pt.x < fin.x)
			{
				pos = pt.x * 4 + img.size_line * pt.y;
				if (img.data[pos])
					return (1);
			}
		}
	}
	return (0);
}

void	move_key_back(t_player *hero, t_img img, int *l)
{
	double	move;
	t_vect	end;

	if (*l == 1)
	{
		*l = 2;
		return ;
	}
	if (*l == 0)
		*l = 1;
	move = (hero->speed * 3);
	end.y = move * cos(convert(hero->angle));
	end.x = move * sin(convert(hero->angle));
	if (!is_wall_around(*hero, img, end))
	{
		hero->vec.y += move
			* cos(convert(hero->angle));
		hero->vec.x += move
			* sin(convert(hero->angle));
	}
}

int	display(t_param *param)
{
	if (param->move.s)
		move_key_back(&param->hero, param->img_map, &param->move.s);
	if (param->move.w)
		move_key_forward(&param->hero, param->img_map, &param->move.w);
	if (param->move.a)
		move_key_left(&param->hero, param->img_map, &param->move.a);
	if (param->move.d)
		move_key_right(&param->hero, param->img_map, &param->move.d);
	if (param->move.r)
		pov_right(&param->move.r, &param->hero);
	if (param->move.l)
		pov_left(&param->move.l, &param->hero);
	param->hero.angle = get_angle_right(param->hero.angle, 0);
	display_multi_angle(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img.image, 0, 0);
	return (1);
}
