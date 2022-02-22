/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:30:31 by abrun             #+#    #+#             */
/*   Updated: 2022/02/22 11:24:41 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	check_adjacent(char **map, int x, int y, int line)
{
	if (x < 1 || y < 1 || x >= line)
		return (EXIT_FAILURE);
	if (map[x + 1] && (is_whitespace(map[x + 1][y]) || is_whitespace(map[x - 1][y])))
		return (EXIT_FAILURE);
	if (is_whitespace(map[x][y + 1]) || is_whitespace(map[x][y - 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_surrounded(int line, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map && map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0')
			{
				if (check_adjacent(map, x, y, line) == EXIT_FAILURE)
				{
					ft_putstr_fd("Error\nLa map n'est pas fermee !\n", 2);
					return (0);
				}
			}
			y++;
		}
		x++;
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
