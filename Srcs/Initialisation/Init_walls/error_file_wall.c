/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:24:34 by abrun             #+#    #+#             */
/*   Updated: 2022/02/02 12:52:23 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

void	error_file_wall(t_param *param, char *file)
{
	ft_putstr_fd("Error\nLe fichier ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" n'est pas valide\n", 2);
	free_init_walls(param);
	free_mlx(param);
	exit(1);
}
