/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:00:55 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 13:20:55 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	move_hero(int key, t_param *param)
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
		move_key_back(&param->hero, param->img_map);
	else if (key == 'w')
		move_key_forward(&param->hero, param->img_map);
	else if (key == 'a')
		move_key_left(&param->hero, param->img_map);
	else if (key == 'd')
		move_key_right(&param->hero, param->img_map);
	else if (key == 65363)
		param->hero.angle -= 1;
	else if (key == 65361)
		param->hero.angle += 1;
	param->hero.angle = get_angle_right(param->hero.angle, 0);
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
