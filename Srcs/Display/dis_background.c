/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:06:40 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 12:27:45 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	display_background(int start_y, t_param *param, int wall_h, int pos_x)
{
	display_roof(param, wall_h + start_y, pos_x, param->img.size_line);
	display_floor(param, start_y, pos_x, param->img.size_line);
}

void	display_floor(t_param *param, int start_y, int x, int size_line)
{
	int		y;
	int		pos;

	y = start_y;
	if (y < 0)
		y = 0;
	while (y < param->height)
	{
		pos = x * 4 + size_line * y;
		param->img.data[pos] = param->floor[2];
		param->img.data[pos + 1] = param->floor[1];
		param->img.data[pos + 2] = param->floor[0];
		y++;
	}
}

void	display_roof(t_param *param, int start_y, int x, int size_line)
{
	int		y;
	int		pos;

	y = 0;
	while (y < start_y && y < param->height / 2)
	{
		pos = x * 4 + size_line * y;
		param->img.data[pos] = param->roof[2];
		param->img.data[pos + 1] = param->roof[1];
		param->img.data[pos + 2] = param->roof[0];
		y++;
	}
}
