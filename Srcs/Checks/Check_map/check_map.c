/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:35:41 by abrun             #+#    #+#             */
/*   Updated: 2022/02/02 13:39:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	is_pos_hero(char **map)
{
	int	x;
	int	y;
	int	pos;

	y = 0;
	pos = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' ||
				map[y][x] == 'S' || map[y][x] == 'W')
				pos++;
			x++;
		}
		y++;
	}
	if (pos != 1)
	{
		ft_putstr_fd("Error\nIl y a un probleme avec le répère du héro !\n", 2);
		return (0);
	}
	return (1);
}

int	is_characters_ok(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'N' && map[y][x] != 'E'
				&& map[y][x] != 'S' && map[y][x] != 'W'
				&& map[y][x] != '1'
				&& map[y][x] != 32 && map[y][x] != '0')
			{
				ft_putstr_fd("Error\nIl y a un caractere indesirable !\n", 2);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
