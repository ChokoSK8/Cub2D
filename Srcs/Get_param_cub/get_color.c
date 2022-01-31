/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:55:36 by abrun             #+#    #+#             */
/*   Updated: 2022/01/31 13:57:41 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_color(char *line, t_param *param, int d)
{
	int		*tab;
	int		ret;

	if (!check_color(d, line))
		return (0);
	tab = get_color_fill_tab(line);
	if (!tab)
		return (0);
	if (d == 'F')
	{
		if (!(fill_floor(param, tab)))
			ret = 0;
		else
			ret = 5;
	}
	else
	{
		if (!(fill_roof(param, tab)))
			ret = 0;
		else
			ret = 6;
	}
	free(tab);
	return (ret);
}

int	*get_color_fill_tab(char *line)
{
	int		*tab;

	tab = malloc(sizeof(int) * 3);
	if (!tab)
	{
		ft_putstr_fd("Error\nUn malloc a échoué ! \n", 2);
		return (0);
	}
	while (*line && !ft_isdigit(*line))
		line++;
	tab[0] = ft_atoi(line);
	while (*line && *line != ',')
		line++;
	tab[1] = ft_atoi(++line);
	while (*line && *line != ',')
		line++;
	tab[2] = ft_atoi(++line);
	return (tab);
}

int	fill_floor(t_param *param, int *tab)
{
	int		counter;

	if (param->checks[4])
	{
		ft_putstr_fd("Error\nIl y a 2 fois la couleur du sol !\n", 2);
		return (0);
	}
	counter = 0;
	param->floor = malloc(sizeof(int) * 3);
	if (!param->floor)
	{
		ft_putstr_fd("Error\nUn malloc a échoué ! \n", 2);
		return (0);
	}
	while (counter < 3)
	{
		param->floor[counter] = tab[counter];
		counter++;
	}
	return (1);
}

int	fill_roof(t_param *param, int *tab)
{
	int		counter;

	if (param->checks[5])
	{
		ft_putstr_fd("Error\nIl y a 2 fois la couleur du toit !\n", 2);
		return (0);
	}
	counter = 0;
	param->roof = malloc(sizeof(int) * 3);
	if (!param->roof)
	{
		ft_putstr_fd("Error\nUn malloc a échoué ! \n", 2);
		return (0);
	}
	while (counter < 3)
	{
		param->roof[counter] = tab[counter];
		counter++;
	}
	return (1);
}
