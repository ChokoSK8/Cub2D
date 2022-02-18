/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:00:55 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 14:21:31 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	keypressed(int key, t_param *param)
{
	if (key == 65307)
	{
		free_param(param);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
	if (key == 's')
		param->move.s = 1;
	else if (key == 'w')
		param->move.w = 1;
	else if (key == 'a')
		param->move.a = 1;
	else if (key == 'd')
		param->move.d = 1;
	else if (key == 65363)
		param->move.r = 1;
	else if (key == 65361)
		param->move.l = 1;
	return (1);
}

int	keyreleased(int key, t_param *param)
{
	if (key == 's')
		param->move.s = 0;
	else if (key == 'w')
		param->move.w = 0;
	else if (key == 'a')
		param->move.a = 0;
	else if (key == 'd')
		param->move.d = 0;
	else if (key == 65363)
		param->move.r = 0;
	else if (key == 65361)
		param->move.l = 0;
	return (1);
}

void	move_key_left(t_player *hero, t_img img)
{
	t_vect	h;

	h.y = hero->vec.y - hero->speed
		* cos(convert(hero->angle + 90));
	h.x = hero->vec.x - hero->speed
		* sin(convert(hero->angle + 90));
	if (!is_wall_around(h, img))
	{
		hero->vec.y -= hero->speed
			* cos(convert(hero->angle + 90));
		hero->vec.x -= hero->speed
			* sin(convert(hero->angle + 90));
	}
}

void	move_key_right(t_player *hero, t_img img)
{
	t_vect	h;

	h.y = hero->vec.y - hero->speed
		* cos(convert(hero->angle - 90));
	h.x = hero->vec.x - hero->speed
		* sin(convert(hero->angle - 90));
	if (!is_wall_around(h, img))
	{
		hero->vec.y -= hero->speed
			* cos(convert(hero->angle - 90));
		hero->vec.x -= hero->speed
			* sin(convert(hero->angle - 90));
	}
}

void	move_key_forward(t_player *hero, t_img img)
{
	t_vect	h;

	h.y = hero->vec.y - hero->speed
		* cos(convert(hero->angle));
	h.x = hero->vec.x - hero->speed
		* sin(convert(hero->angle));
	if (!is_wall_around(h, img))
	{
		hero->vec.y -= hero->speed
			* cos(convert(hero->angle));
		hero->vec.x -= hero->speed
			* sin(convert(hero->angle));
	}
}
