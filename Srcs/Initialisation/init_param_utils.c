/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:54:51 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 14:13:10 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	init_move(t_move *move)
{
	move->w = 0;
	move->a = 0;
	move->s = 0;
	move->d = 0;
	move->r = 0;
	move->l = 0;
}

int	get_dist_max(t_map map)
{
	if (map.max_width < map.height)
		return (map.len_pix * map.height);
	else
		return (map.max_width * map.len_pix);
}
