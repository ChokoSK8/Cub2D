/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:11:26 by abrun             #+#    #+#             */
/*   Updated: 2022/02/24 15:25:53 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	pov_left(int *l, t_player *hero)
{
	if (*l == 1)
	{
		*l = 2;
		return ;
	}
	if (*l == 0)
		*l = 1;
	hero->angle += 1;
}

void	pov_right(int *l, t_player *hero)
{
	if (*l == 1)
	{
		*l = 2;
		return ;
	}
	if (*l == 0)
		*l = 1;
	hero->angle -= 1;
}
