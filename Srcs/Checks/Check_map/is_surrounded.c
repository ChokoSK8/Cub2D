/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:31 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 14:25:25 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int check_adjacent(char **map, int x, int y, int line)
{
	if (x < 1 || y < 1 || x >= (line))
		return (EXIT_FAILURE);
	if (is_whitespace(map[x + 1][y]) || is_whitespace(map[x - 1][y]))
		return(EXIT_FAILURE);
	if (is_whitespace(map[x][y + 1]) || is_whitespace(map[x][y - 1]))
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

bool is_map_open(char **map, int line)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(map && map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0')
			{
				if (check_adjacent(map, x , y, line) == EXIT_FAILURE)
					return (true);
			}
			y++;
		}
		x++;
	}
	return(false);
}

int	is_surrounded(int height, int width, char **map)
{
	t_point	pt;

	pt.y = 0;
	while (map[pt.y])
	{
		pt.x = 0;
		while (map[pt.y][pt.x])
		{
			if ((map[pt.y][pt.x] == '0' || map[pt.y][pt.x] == 'N'
				|| map[pt.y][pt.x] == 'W' || map[pt.y][pt.x] == 'S'
				|| map[pt.y][pt.x] == 'E')
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
