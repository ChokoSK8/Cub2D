/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:31 by abrun             #+#    #+#             */
/*   Updated: 2021/10/29 17:03:02 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	is_surrounded(int height, int width, char **map)
{
	t_point	pt;

	pt.y = 0;
	while (map[pt.y])
	{
		pt.x = 0;
		while (map[pt.y][pt.x])
		{
			if (map[pt.y][pt.x] == '0'
				&& !check_around(map, pt, height, width))
			{
				ft_putstr_fd("Error\nLa map n'est pas fermee !\n", 2);
				return (0);
			}
			pt.x++;
		}
		pt.y++;
	}
	return (1);
}

int	check_around(char **map, t_point pt, int height, int width)
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
				&& map[chi.y][chi.x] != '1')
			{
				chi.x -= (pt.x - wit.x);
				chi.y -= (pt.y - wit.y);
			}
			if (!is_pt_valid(chi, height, width))
				return (0);
			wit.x++;
		}
		wit.y++;
	}
	return (1);
}

int	is_pt_valid(t_point pt, int height, int width)
{
	if ((pt.x >= 0 && pt.x < width)
		&& (pt.y >= 0 && pt.y < height))
		return (1);
	return (0);
}
