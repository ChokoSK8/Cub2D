/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:31:43 by abrun             #+#    #+#             */
/*   Updated: 2022/02/02 12:50:51 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	free_init_walls(t_param *param)
{
	int	counter;

	counter = 0;
	free(param->no);
	free(param->so);
	free(param->ea);
	free(param->we);
	free(param->floor);
	free(param->roof);
	while (param->map.map[counter])
		free(param->map.map[counter++]);
	free(param->map.map);
	if (!free_wall(param, param->walls.wall1.img.image))
		return ;
	if (!free_wall(param, param->walls.wall2.img.image))
		return ;
	if (!free_wall(param, param->walls.wall3.img.image))
		return ;
	if (!free_wall(param, param->walls.wall4.img.image))
		return ;
}

int	free_wall(t_param *param, void *img)
{
	if (img)
		mlx_destroy_image(param->mlx, img);
	else
		return (0);
	return (1);
}

void	free_in_loop_tab(t_param *param, int i, char **map, char *tab)
{
	free_in_loop(param, i, map);
	free(tab);
}
