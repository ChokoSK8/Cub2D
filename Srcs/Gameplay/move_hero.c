/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:00:55 by abrun             #+#    #+#             */
/*   Updated: 2022/02/24 15:30:09 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	keypressed(int key, t_param *param)
{
	if (key == 65307)
	{
		mlx_do_key_autorepeaton(param->mlx);
		free_param(param);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
	if (key == 's')
		move_key_back(&param->hero, param->img_map, &param->move.s);
	else if (key == 'w')
		move_key_forward(&param->hero, param->img_map, &param->move.w);
	else if (key == 'a')
		move_key_left(&param->hero, param->img_map, &param->move.a);
	else if (key == 'd')
		move_key_right(&param->hero, param->img_map, &param->move.d);
	else if (key == 65363)
		pov_right(&param->move.r, &param->hero);
	else if (key == 65361)
		pov_left(&param->move.l, &param->hero);
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

void	move_key_left(t_player *hero, t_img img, int *l)
{
	t_vect	end;

	if (*l == 1)
	{
		*l = 2;
		return ;
	}
	if (*l == 0)
		*l = 1;
	end.y = -hero->speed
		* cos(convert(hero->angle + 90));
	end.x = -hero->speed
		* sin(convert(hero->angle + 90));
	if (!is_wall_around(*hero, img, end))
	{
		hero->vec.y -= hero->speed
			* cos(convert(hero->angle + 90));
		hero->vec.x -= hero->speed
			* sin(convert(hero->angle + 90));
	}
}

void	move_key_right(t_player *hero, t_img img, int *l)
{
	t_vect	end;

	if (*l == 1)
	{
		*l = 2;
		return ;
	}
	if (*l == 0)
		*l = 1;
	end.y = -hero->speed
		* cos(convert(hero->angle - 90));
	end.x = -hero->speed
		* sin(convert(hero->angle - 90));
	if (!is_wall_around(*hero, img, end))
	{
		hero->vec.y -= hero->speed
			* cos(convert(hero->angle - 90));
		hero->vec.x -= hero->speed
			* sin(convert(hero->angle - 90));
	}
}

void	move_key_forward(t_player *hero, t_img img, int *l)
{
	t_vect	end;
	double	move;

	if (*l == 1)
	{
		*l = 2;
		return ;
	}
	if (*l == 0)
		*l = 1;
	move = hero->speed * 3;
	end.y = -move * cos(convert(hero->angle));
	end.x = -move * sin(convert(hero->angle));
	if (!is_wall_around(*hero, img, end))
	{
		hero->vec.y -= move
			* cos(convert(hero->angle));
		hero->vec.x -= move
			* sin(convert(hero->angle));
	}
}
