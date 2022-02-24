/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:24:34 by abrun             #+#    #+#             */
/*   Updated: 2022/02/22 14:16:38 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	error_file_wall(t_param *param, char *file)
{
	ft_putstr_fd("Error\nLe fichier ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" n'est pas valide\n", 2);
	free_init_walls(param);
	free_mlx(param);
	exit(1);
}

int	error_init_img(t_param *param)
{
	ft_putstr_fd("Error\nL'initialisation de l'image par mlx a echoue !\n", 2);
	free_init_walls(param);
	free_mlx(param);
	exit(1);
}

int	error_init_win(t_param *param)
{
	mlx_destroy_image(param->mlx, param->img.image);
	ft_putstr_fd("Error\nL'initialisation de la window par mlx a echoue !\n", 2);
	free_init_walls(param);
	free_mlx(param);
	exit(1);
}
