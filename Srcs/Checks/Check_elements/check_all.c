/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:45:11 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 13:54:44 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int	check_all(int *checks, t_param *param)
{
	int		counter;

	counter = 0;
	while (counter < 6)
	{
		if (checks[counter] != 1)
		{
			ft_putstr_fd("Error\nIl n'y a pas tous les éléments !\n", 1);
			free_tab_checks(param);
			return (0);
		}
		counter++;
	}
	return (1);
}
