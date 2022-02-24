/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 09:43:32 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 14:37:46 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

double	modulo(double x, int a)
{
	double	dec;
	double	mod;

	dec = x - (int)x;
	mod = (int)x % a;
	mod += dec;
	return (mod);
}

int	get_loc_y(double angle, t_vect pt, t_param param)
{
	int	loc_y;
	int	pt_y;

	pt_y = (int)pt.y;
	if (angle < 90 || angle > 270)
	{
		if (!(pt.y - (double)pt_y) && !((int)pt.y % param.map.len_pix))
			loc_y = pt.y / param.map.len_pix - 1;
		else
			loc_y = pt.y / param.map.len_pix;
	}
	else
		loc_y = pt.y / param.map.len_pix;
	return (loc_y);
}

double	convert(double degre)
{
	double	rad;

	rad = degre / 57.2958;
	return (rad);
}
