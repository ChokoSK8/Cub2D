/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_get_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:55:10 by abrun             #+#    #+#             */
/*   Updated: 2022/02/18 11:59:34 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	exit_get_param(t_param *param, int fd)
{
	if (fd != -1)
		close(fd);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	ft_putstr_fd("Error\nLe fichier n'a pas pu être ouvert !\n", 2);
	return (0);
}
