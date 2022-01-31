/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space_in_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:05:24 by abrun             #+#    #+#             */
/*   Updated: 2021/11/02 14:15:44 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	is_space_in_map(char **map, int height, int width)
{
	t_point	pt;

	pt.y = 0;
	while (map[pt.y])
	{
		pt.x = 0;
		while (map[pt.y][pt.x])
		{
			pt.x = move_ptx_to_sp(map, pt);
			if (map[pt.y][pt.x] == 32)
			{
				if (is_last_sp(map, pt))
					pt.x = width - 1;
				else if (!check_around_sp(map, pt, height, width))
				{
					ft_putstr_fd("Error\nEspace dans la map\n", 2);
					return (1);
				}
			}
			if (map[pt.y][pt.x])
				pt.x++;
		}
		pt.y++;
	}
	return (0);
}

int	move_ptx_to_sp(char **map, t_point pt)
{
	while (map[pt.y][pt.x] && map[pt.y][pt.x] == 32)
		pt.x++;
	while (map[pt.y][pt.x] && map[pt.y][pt.x] != 32)
		pt.x++;
	return (pt.x);
}

int	is_last_sp(char **map, t_point pt)
{
	while (map[pt.y][pt.x] && map[pt.y][pt.x] == 32)
		pt.x++;
	if (map[pt.y][pt.x])
		return (0);
	return (1);
}

int	check_around_sp(char **map, t_point pt, int height, int width)
{
	t_point	wit;
	t_point	chi;

	wit.y = pt.y - 1;
	while (wit.y < pt.y + 2)
	{
		wit.x = pt.x - 1;
		while (wit.x < pt.x + 2)
		{
			chi.x = wit.x;
			chi.y = wit.y;
			while (is_pt_valid(chi, height, width)
				&& (chi.x != pt.x || chi.y != pt.y)
				&& map[chi.y][chi.x] == 32)
				chi = get_chi(chi, pt, wit);
			if (is_pt_valid(chi, height, width)
				&& (map[chi.y][chi.x] != '1'
				&& (chi.x != pt.x || chi.y != pt.y)))
				return (0);
			wit.x++;
		}
		wit.y++;
	}
	return (1);
}

t_point	get_chi(t_point chi, t_point pt, t_point wit)
{
	chi.x -= (pt.x - wit.x);
	chi.y -= (pt.y - wit.y);
	return (chi);
}
